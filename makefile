CXX      := -c++
CXXFLAGS := -std=c++14 #-pedantic-errors -Wall #-Wextra -Werror
LDFLAGS  :=-static-libstdc++ -lm -L/home/JZhang/programs/gsl2.4/lib -lgsl -lgslcblas -lnetcdf_c++
BUILD    := ./_build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := program
#INCLUDE  := -Iinclude/ -I/home/dwang/miniconda3/include/
#INCLUDE  := -Iinclude/ -I/home/muye/Downloads/ls/include/
INCLUDE  := -Iinclude/ -I/home/JZhang/programs/xtensor/include/
SRC      :=                      \
   $(wildcard src/module1/*.cpp) \
   $(wildcard src/module2/*.cpp) \
   $(wildcard src/module3/*.cpp) \
   $(wildcard src/*.cpp)         \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

run:
	@$(APP_DIR)/$(TARGET)

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*
