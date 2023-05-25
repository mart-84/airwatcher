EXEC = airwatcher
SRCS = src/metier/Attribut.cpp src/metier/Capteur.cpp src/metier/Fournisseur.cpp \
       src/metier/Mesure.cpp src/metier/Particulier.cpp src/metier/Purificateur.cpp \
	   src/service/Service.cpp src/vue/Vue.cpp src/dao/CapteurDao.cpp src/dao/Dao.cpp \
	   src/main.cpp

PS = /
OBJDIR := obj
GCC = g++
CFLAGS = -g -Wall
LDFLAGS = -g -Wall

MOVE = mv -f
RM = rm -rf
MKDIR = mkdir -p
TOUCH = touch $(1)
NULL_FILE = /dev/null

ifeq ($(OS), Windows_NT) # Version spéciale Windows
EXEC := $(EXEC).exe
PS = \\
MOVE = move
RM = del /Q /F /S
MKDIR = md
TOUCH = type nul >>$(1) & copy $(1) +,,
NULL_FILE = nul
else
EXEC := ./$(EXEC)
endif

DEPDIR :=  $(OBJDIR)$(PS)dependencies
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)$(PS)$*.d

all: $(EXEC)
	@echo Build finished

$(EXEC): $(SRCS:%.cpp=$(OBJDIR)/%.o)
	$(GCC) $(LDFLAGS) -o $@ $^ $(LIBS)


$(OBJDIR)/%.o : %.cpp $(DEPDIR)/%.d $(DEPDIR)
	@$(MKDIR) $(subst /,$(PS), $(dir $@)) > $(NULL_FILE) 2>&1 ||:
	@$(MKDIR) $(subst $(OBJDIR),$(DEPDIR),$(subst /,$(PS), $(dir $@))) > $(NULL_FILE) 2>&1 ||:
	$(GCC) $(DEPFLAGS) $(CFLAGS) -c $< -o $@

$(DEPDIR):
	@$(MKDIR) $@ ||:

DEPFILES := $(SRCS:%.cpp=$(DEPDIR)/%.d)
$(DEPFILES):
include $(wildcard $(DEPFILES))

clean:
ifeq ($(OS), Windows_NT) # Version spéciale Windows
	rmdir /S /Q $(OBJDIR) > $(NULL_FILE) 2>&1 ||:
endif
	$(RM) obj $(EXEC) > $(NULL_FILE) 2>&1 ||:


ifneq ($(findstring create, $(MAKECMDGOALS)),)
-include makefile_data$(PS)class_generator.make
endif