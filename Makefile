CXX = clang++
CXXFLAGS = -std=c++11 -stdlib=libc++
FLTK_LIBS = -lfltk
FLTK_INCLUDE = /usr/include
SRCS = src/main.cpp 
OUTPUT = editor

$(OUTPUT): $(SRCS)
	$(CXX) $(CXXFLAGS) -I$(FLTK_INCLUDE) $(SRCS) -o $(OUTPUT) $(FLTK_LIBS) -lc++abi

clean:
	rm -f $(OUTPUT)