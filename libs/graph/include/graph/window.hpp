#ifndef GRAPH_WINDOW_HPP
#define GRAPH_WINDOW_HPP

#include <string>

#include <graph/noncopyable.hpp>
#include <graph/sdl2.hpp>

struct SDL_Window;

namespace graph {

class window : protected noncopyable {
	friend class render;
	friend class window_manager;
	unsigned w, h;
	sdl2 _;
	SDL_Window* m_window;
	std::mutex m_mutex;
public:
	window(const std::string& title);

	inline unsigned get_w() { return w; }
	inline unsigned get_h() { return h; }
};

}

#endif /* GRAPH_WINDOW_HPP */
