CXX := g++
CXXFLAGS := -std=c++17 -O3 -Wall
LDFLAGS := -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

# Directories
BUILD_DIR := build
BIN_DIR := bin
MODULES := Core Armes Ennemis States Bullets

# Object files
MAIN := main.cpp

MAIN_OBJ := $(BUILD_DIR)/main.o
MODULE_OBJS := $(foreach module,$(MODULES),$(shell $(MAKE) -s -C $(module) objs))
#SUBIDRS := $(addprefix, $(BUILD_DIR)/,$(foreach module,$(MODULES),$(shell $(MAKE) -s -C $(module) subdirs)))
SUBDIRS := build/Armes_Variants build/Ennemis_Variants build/Bullets_Variants
OBJS := $(MAIN_OBJ) $(MODULE_OBJS)

TARGET := $(BIN_DIR)/witch-survival

.PHONY: all clean $(MODULES)

all: $(BIN_DIR) $(BUILD_DIR) $(SUBDIRS) $(TARGET)

# Link the final program and everything
$(TARGET): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Build the program object file
$(MAIN_OBJ): $(MAIN)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build a module obj file assuming pattern Module_Component.o
$(MODULE_OBJS):
	@mod=$(notdir $(word 1,$(subst _, ,$*))); \
	echo "building obj $@ inside $$mod"; \
	$(MAKE) -C $$mod $@

# Create bin / build dirs if necessary
$(BIN_DIR) $(BUILD_DIR) $(SUBDIRS):
	echo "Creating output directory $@"; \
	mkdir -p $@

# Build modules
$(MODULES):
	echo "Building module $@"; \
	$(MAKE) -C $@

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
	@for module in $(MODULES); do $(MAKE) -C $$module clean; done
