CXX = g++
FLAGS = -O2 -Wall -Werror -Wextra
CFLAGS = $(FLAGS) -Iinclude

all: libgraph.a

libgraph.a: sdl2.o window.o render.o window_manager.o
	ar -rv libgraph.a sdl2.o window.o render.o window_manager.o

sdl2.o: src/sdl2.cpp include/graph/noncopyable.hpp include/graph/sdl2.hpp \
		include/graph/sdl2headers.hpp
	$(CXX) -c src/sdl2.cpp $(CFLAGS)

window.o: src/window.cpp
	$(CXX) -c src/window.cpp $(CFLAGS)
	
render.o: src/render.cpp
	$(CXX) -c src/render.cpp $(CFLAGS)
	
window_manager.o: src/window_manager.cpp
	$(CXX) -c src/window_manager.cpp $(CFLAGS)
	
clean:
	rm *.o libgraph.a

