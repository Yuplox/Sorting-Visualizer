# makefile inspired by
# https://spin.atomicobject.com/2016/08/26/makefile-c-projects/
# and https://makefiletutorial.com/

# Final executable after running make
TARGET_EXEC := test.out

# location of build and source directories
BUILD_DIR := ./build
SRC_DIRS := ./src

# Finds all .cpp files 
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

# Creates list of corresponding .o and .d files
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

# Finds all directories in src and formats them as include flags
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS := $(INC_FLAGS) -MMD -MP

# Final build step
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

# Include the .d makefiles
# - suppresses the errors for missing Makefiles
-include $(DEPS)
