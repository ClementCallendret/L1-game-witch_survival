MODULE := Armes
BUILD_DIR := ../build

SUBDIRS := Variants

CXX := g++
CXXFLAGS := -std=c++17 -O3 -Wall -I. -I./Variants -I../Ennemis -I../Bullets -I../Armes -I../Core -MMD -MP

SRC := $(wildcard *.cpp) $(foreach dir, $(SUBDIRS), $(wildcard $(dir)/*.cpp))
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/$(MODULE)_%.o,$(SRC))
DEPS := $(OBJS:.o=.d)

-include $(DEPS)

.PHONY: all objs subdirs clean

all: $(OBJS)

objs:
	@echo $(OBJS)

subdirs:
	@echo $(addprefix $(MODULE)_,$(SUBDIRS))

$(BUILD_DIR)/$(MODULE)_%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/$(MODULE)_*.o $(BUILD_DIR)/$(MODULE)_*.d