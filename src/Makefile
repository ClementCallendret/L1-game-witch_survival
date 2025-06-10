MSQ = @
CXX := g++
CXXFLAGS := -std=c++17 -O3 -Wall
LDFLAGS := -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

BUILD_DIR := ../build
BIN_DIR := ../bin
DEP_DIR := ../.dep

PROG := $(BIN_DIR)/witch-survival
MODULES := Core States Bullets Armes Ennemis

Core_DIRS := Core
Core_INCLUDES := -ICore

States_DIRS := States
States_INCLUDES := -IStates -IEnnemis -IEnnemis/Variants -IBullets  -ICore -IArmes -IArmes/Variants

Bullets_DIRS := Bullets Bullets/Variants
Bullets_INCLUDES := -IBullets -ICore -IBullets/Variants -IEnnemis

Armes_DIRS := Armes Armes/Variants
Armes_INCLUDES := -IArmes -IArmes/Variants -IEnnemis -IBullets -IArmes -ICore

Ennemis_DIRS := Ennemis Ennemis/Variants
Ennemis_INCLUDES := -IEnnemis -ICore -IEnnemis/Variants

MAIN := $(BUILD_DIR)/main.o
MAIN_INCLUDES := -IStates

OBJS := $(MAIN)

REQUIRED_DIRS := $(DEP_DIR) $(BUILD_DIR) $(BIN_DIR)

define add_module =
  $(eval cur_src := $(foreach dir, $($(1)_DIRS), $(wildcard $(dir)/*.cpp)))
  $(eval $(1)_OBJS := $(patsubst %.cpp,$(BUILD_DIR)/$(1)_%.o,$(cur_src)))
  $(BUILD_DIR)/$(1)_%.o: %.cpp
	@echo "Compilation du fichier '$$<' en '$$@'"
	$(MSQ)$(CXX) $(CXXFLAGS) $($(1)_INCLUDES) -MT $$@ -MMD -MP -MF $(DEP_DIR)/$$(subst /,.,$$(@:.o=.depend)) -c -o $$@ $$<
  OBJS += $($(1)_OBJS)
  REQUIRED_DIRS += $$(addprefix $(BUILD_DIR)/$(1)_,$($(1)_DIRS))
endef

$(foreach module, $(MODULES),$(eval $(call add_module,$(module))))


# Cibles factices
.PHONY: all clean

MISSING_DIRS := $(filter-out $(wildcard $(REQUIRED_DIRS)), $(REQUIRED_DIRS))
ifeq ($(MISSING_DIRS),)
all: $(PROG)
include $(wildcard $(DEP_DIR)/*)
else
all: $(REQUIRED_DIRS)
	$(MAKE)
endif

$(PROG): $(OBJS)
	@echo "Génération du programme '$@' à partir des fichiers objets"
	$(MSQ)$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(MAIN): main.cpp
	@echo "Compilation du fichier '$<' en '$@'"
	$(MSQ)$(CXX) $(CXXFLAGS) -MT $@ -MMD -MP -MF $(DEP_DIR)/$(@:$(BUILD_DIR)%.o=%.depend) -c -o $@ $< $(MAIN_INCLUDES)

# Répertoire build / bin / .dep
$(REQUIRED_DIRS):
	@echo "Création du répertoire '$@'"
	$(MSQ)mkdir -p "$@"

# Nettoyage
clean:
	@echo "Suppression du répertoire contenant les dépendances ($(DEP_DIR))"
	$(MSQ)rm -rf $(DEP_DIR)
	@echo "Suppression du répertoire contenant les fichers objets ($(BUILD_DIR))"
	$(MSQ)rm -rf $(BUILD_DIR)
	@echo "Suppression du répertoire contenant les programmes ($(BIN_DIR))"
	$(MSQ)rm -rf $(BIN_DIR)
	@echo "Suppression des fichiers de backup"
	$(MSQ)rm -f *~
	@echo