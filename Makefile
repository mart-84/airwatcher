EXEC = airwatcher
SRCS = src/metier/Attribut.cpp src/metier/Capteur.cpp src/metier/Fournisseur.cpp \
       src/metier/Mesure.cpp src/metier/Particulier.cpp src/metier/Purificateur.cpp \
	   src/service/Service.cpp src/vue/VueConsole.cpp \
	   src/dao/csv/CsvParser.cpp src/dao/csv/AttributDaoCsv.cpp src/dao/csv/FournisseurDaoCsv.cpp \
	   src/dao/csv/MesureDaoCsv.cpp src/dao/csv/ParticulierDaoCsv.cpp \
	   src/dao/csv/PurificateurDaoCsv.cpp src/dao/csv/CapteurDaoCsv.cpp 

MAIN = src/main.cpp

ifeq ($(findstring test, $(MAKECMDGOALS)),)
SRCS += $(MAIN)
endif

TEST_SRCS = tests/main.cpp
TEST_OBJDIR = obj_tests
TEST_EXEC = test

PS = /
OBJDIR = obj
GCC = g++
CFLAGS = -g -Wall -Werror -Wpedantic -O3
LDFLAGS = -g -Wall -Werror -Wpedantic -O3

MOVE = mv -f
RM = rm -rf
MKDIR = mkdir -p
TOUCH = touch $(1)
NULL_FILE = /dev/null

ifeq ($(OS), Windows_NT) # Version spéciale Windows
EXEC := $(EXEC).exe
TEST_EXEC := $(TEST_EXEC).exe
PS = \\
MOVE = move
RM = del /Q /F /S
MKDIR = md
TOUCH = type nul >>$(1) & copy $(1) +,,
NULL_FILE = nul
else
EXEC := ./$(EXEC)
TEST_EXEC := ./$(TEST_EXEC)
endif

DEPDIR :=  $(OBJDIR)$(PS)dependencies
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)$(PS)$*.d

TEST_DEPDIR := $(TEST_OBJDIR)$(PS)dependencies
TEST_DEPFLAGS = -MT $@ -MMD -MP -MF $(TEST_DEPDIR)$(PS)$*.d

all: $(EXEC)
	@echo Build finished

$(EXEC): $(SRCS:%.cpp=$(OBJDIR)/%.o)
	$(GCC) $(LDFLAGS) -o $@ $^ $(LIBS)

tests: $(TEST_EXEC)
	@echo Test build finished

$(TEST_EXEC): $(TEST_SRCS:%.cpp=$(TEST_OBJDIR)/%.o) $(SRCS:%.cpp=$(OBJDIR)/%.o)
	$(GCC) $(LDFLAGS) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o : %.cpp $(DEPDIR)/%.d $(DEPDIR)
	@$(MKDIR) $(subst /,$(PS), $(dir $@)) > $(NULL_FILE) 2>&1 ||:
	@$(MKDIR) $(subst $(OBJDIR),$(DEPDIR),$(subst /,$(PS), $(dir $@))) > $(NULL_FILE) 2>&1 ||:
	$(GCC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@

$(TEST_OBJDIR)/%.o : %.cpp $(TEST_DEPDIR)/%.d
	@$(MKDIR) $(subst /,$(PS), $(dir $@)) > $(NULL_FILE) 2>&1 ||:
	@$(MKDIR) $(subst $(TEST_OBJDIR),$(TEST_DEPDIR),$(subst /,$(PS), $(dir $@))) > $(NULL_FILE) 2>&1 ||:
	$(GCC) $(TEST_DEPFLAGS) $(CFLAGS) -c $< -o $@

$(DEPDIR):
	@$(MKDIR) $@ > $(NULL_FILE) 2>&1 ||:

DEPFILES := $(SRCS:%.cpp=$(DEPDIR)/%.d)
$(DEPFILES):
include $(wildcard $(DEPFILES))

TEST_DEPFILES := $(TEST_SRCS:%.cpp=$(TEST_DEPDIR)/%.d)
$(TEST_DEPFILES):
include $(wildcard $(TEST_DEPFILES))

clean:
ifeq ($(OS), Windows_NT) # Version spéciale Windows
	rmdir /S /Q $(OBJDIR) > $(NULL_FILE) 2>&1 ||:
	rmdir /S /Q $(TEST_OBJDIR) > $(NULL_FILE) 2>&1 ||:
	$(RM) $(EXEC) > $(NULL_FILE) 2>&1 ||:
	$(RM) $(TEST_EXEC) > $(NULL_FILE) 2>&1 ||:
endif
	$(RM) $(OBJDIR) $(TEST_OBJDIR) $(EXEC) > $(NULL_FILE) $(TEST_EXEC) 2>&1 ||:


ifneq ($(findstring create, $(MAKECMDGOALS)),)
-include makefile_data$(PS)class_generator.make
endif
