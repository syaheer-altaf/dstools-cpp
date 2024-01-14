# Source files
SRC_FILES = dslist.cpp dsarray.cpp dsbubblesort.cpp dsheap.cpp dsheapsort.cpp dsmergesort.cpp
# Output shared library name
LIB_NAME = libdstools
# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Werror -fpic -shared
# Compile library
lib_windows: $(SRC_FILES)
	@echo "Creating a shared library for Windows..."
	$(CXX) $(CXXFLAGS) -o $(LIB_NAME).dll $(SRC_FILES)

lib_linux: $(SRC_FILES)
	@echo "Creating a shared library for Linux..."
	$(CXX) $(CXXFLAGS) -o $(LIB_NAME).so $(SRC_FILES)

lib_macos: $(SRC_FILES)
	@echo "Creating a shared library for MacOS..."
	$(CXX) $(CXXFLAGS) -o $(LIB_NAME).dylib $(SRC_FILES)