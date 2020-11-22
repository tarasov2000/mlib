CXX = g++
FLAGS = -O2 -Wall -Werror -Wextra
CFLAGS = $(FLAGS) -Iinclude -I../graph/include

all: libmlib.a

libmlib.a: buffer.o mat.o mlib_render.o polynom.o
	ar -rv libmlib.a buffer.o mat.o mlib_render.o polynom.o

buffer.o: src/buffer.cpp
	$(CXX) -c src/buffer.cpp $(CFLAGS)

mat.o: src/mat.cpp
	$(CXX) -c src/mat.cpp $(CFLAGS)

mlib_render.o: src/mlib_render.cpp
	$(CXX) -c src/mlib_render.cpp $(CFLAGS)

polynom.o: src/polynom.cpp
	$(CXX) -c src/polynom.cpp $(CFLAGS)
	
clean:
	rm *.o libmlib.a

