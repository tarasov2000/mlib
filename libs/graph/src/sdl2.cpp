/**
 * @file sdl2.cpp
 *
 * @brief Stores realization of some methods from sdl2.
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

#include <graph/sdl2.hpp>

#include <stdexcept>
#include <string>
#include <mutex>

#include <graph/sdl2headers.hpp>

using namespace std;

namespace graph {

namespace {

/*! Counter of instances. */
volatile size_t counter = 0;
/*! Mutex for multithreading. */
mutex mut;

}

/*! Initializing SDL2 only once. */
sdl2::sdl2() {
	lock_guard<mutex> lock(mut);
	if (counter == 0) {
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
			throw runtime_error("Unable to initialize SDL2, SDL_Error: " +
					string(SDL_GetError()));
		}
	}
	counter++;
}

/*! Quiting SDL2 only once. */
sdl2::~sdl2() {
	lock_guard<mutex> lock(mut);
	if (counter == 1) {
		SDL_Quit();
	}
	counter--;
}

}

