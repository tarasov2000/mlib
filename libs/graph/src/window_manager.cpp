/**
 * @file window_manager.cpp
 *
 * @brief Stores realization of some methods from window_manager.
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

#include <graph/window_manager.hpp>

#include <mutex>

#include <graph/sdl2headers.hpp>
#include <graph/window.hpp>

using namespace std;

namespace graph {

/*! Singletone realization. */
window_manager& window_manager::get_instance() {
	static window_manager windows;
	return windows;
}

/*! Method get all events from window events queue and catch
	window closings. */
bool window_manager::poll_events() {
	static SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_WINDOWEVENT) {
			if (e.window.event == SDL_WINDOWEVENT_CLOSE) {
				lock_guard<mutex> lock(m_mutex);
				window* w = m_windows[e.window.windowID];
				m_windows.erase(e.window.windowID);
				SDL_DestroyWindow(w->m_window);
			}
		}
	}
	if (m_windows.size() == 0) {
		return false;
	}
	return true;
}

}

