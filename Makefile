CXX = g++
FLAGS = -O2 -Wall -Werror -Wextra
CFLAGS = $(FLAGS) -Ilibs/mlib/include -Ilibs/graph/include
LFLAGS = $(FLAGS) -Llibs/mlib -Llibs/graph

all: ailab

ailab: main.o
	$(MAKE) -C libs/graph
	$(MAKE) -C libs/mlib
	$(CXX) $(LFLAGS) main.o -o ailab -lmlib -lgraph	-lSDL2

main.o: src/main.cpp
	$(CXX) -c src/main.cpp $(CFLAGS)

clean:
	$(MAKE) -C libs/graph clean
	$(MAKE) -C libs/mlib clean
	rm *.o

run:
	./ailab

fullclean: clean
	rm ailab

