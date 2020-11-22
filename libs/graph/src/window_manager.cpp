#include <graph/window_manager.hpp>

#include <mutex>

#include <graph/sdl2headers.hpp>
#include <graph/window.hpp>

using namespace std;

namespace graph {

window_manager& window_manager::get_instance() {
	static window_manager windows;
	return windows;
}

bool window_manager::poll_events() {
	static SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_WINDOWEVENT) {
			if (e.window.event == SDL_WINDOWEVENT_CLOSE) {
				window* w = m_windows[e.window.windowID];
				lock_guard<mutex> lock(w->m_mutex);
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
