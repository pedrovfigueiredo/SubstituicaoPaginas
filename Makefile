EXECUTABLE = algsubspag
SRC_DIR = Sources
CXX = g++

CXXFLAGS = -std=c++14 -Wall -Wextra -Wpedantic -Ofast

SOURCES = $(wildcard Sources/*.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $^ -o $@


.PHONY: clean distclean

clean:
	rm Sources/*.o

distclean: clean
	rm $(EXECUTABLE)
