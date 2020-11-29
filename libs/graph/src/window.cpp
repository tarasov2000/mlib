/**
 * @file window.cpp
 *
 * @brief Stores realization of some methods from window.
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

#include <graph/window.hpp>

#include <stdexcept>
#include <string>

#include <graph/sdl2.hpp>
#include <graph/sdl2headers.hpp>
#include <graph/window_manager.hpp>

using namespace std;

namespace graph {

namespace {

/*! Function for creating window on widnow center. */
SDL_Window* create_window(const char* title, unsigned &w, unsigned &h) {
	SDL_Rect bounds;
	SDL_GetDisplayBounds(0, &bounds);
	w = bounds.w / 2;
	h = bounds.h / 2;
	return SDL_CreateWindow(title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		w, h,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
}

}

/*! Creating window and adding it on window_manager collection. */
window::window(const string& title)
	: m_window(create_window(title.c_str(), w, h)) {
	if (!m_window) {
		throw runtime_error("Unable to create window. SDL_Error: " +
				string(SDL_GetError()));
	}
	window_manager& m = window_manager::get_instance();
	lock_guard<mutex> lock(m.m_mutex);
	m.m_windows.insert({SDL_GetWindowID(m_window), this});
}

}

