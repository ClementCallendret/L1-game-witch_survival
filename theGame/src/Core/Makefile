MODULE := Core
BUILD_DIR := ../build

SUBDIRS :=

CXX := g++
CXXFLAGS := -std=c++17 -O3 -Wall -I. -MMD -MP

SRC := $(wildcard *.cpp) $(foreach dir, $(SUBDIRS), $(wildcard $(dir)/*.cpp))
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/$(MODULE)_%.o,$(SRC))
DEPS := $(OBJS:.o=.d)

-include $(DEPS)

.PHONY: all objs subdirs clean

all: $(OBJS)

objs:
	@echo $(OBJS)

subdirs:
	@echo $(SUBDIRS)

$(BUILD_DIR)/$(MODULE)_%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/$(MODULE)_*.o $(BUILD_DIR)/$(MODULE)_*.d