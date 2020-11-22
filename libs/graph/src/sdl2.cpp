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

#include <graph/sdl2headers.hpp>

using namespace std;

namespace graph {

volatile unsigned long long sdl2::counter = 0;

/*! Initializing SDL2 only once. */
sdl2::sdl2() {
	lock_guard<mutex> lock(m_mutex);
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
	lock_guard<mutex> lock(m_mutex);
	if (counter == 1) {
		SDL_Quit();
	}
	counter--;
}

}

