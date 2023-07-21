CXX = clang++
CXXFLAGS = -std=c++11 -stdlib=libc++
STD_LIB = /usr/include/c++/11/iostream
FLTK_LIBS = -lfltk
FLTK_INCLUDE = /usr/lib/x86_64-linux-gnu/libfltk.so
MAIN = src/main.cpp
OUTPUT = editor

$(OUTPUT): $(MAIN)
	$(CXX) $(CXXFLAGS) $(FLTK_INCLUDE) $(MAIN) -o $(OUTPUT) $(FLTK_LIBS) -lc++abi

clean:
	rm -f $(OUTPUT)