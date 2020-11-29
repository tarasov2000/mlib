#ifndef GRAPH_WINDOW_HPP
#define GRAPH_WINDOW_HPP

/**
 * @file window.hpp
 *
 * @brief Stores definition of window class.
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

#include <string>

#include <graph/noncopyable.hpp>
#include <graph/sdl2.hpp>

struct SDL_Window;

namespace graph {

/*! Class represent window. */
class window : protected noncopyable {
	friend class render;
	friend class window_manager;

	/*! width and height of window. */
	unsigned w, h;

	sdl2 _;

	/*! Pointer to SDL2 window data. */
	SDL_Window* m_window;
public:

	/*! Creates window.
		Can throws `runtime_error` if unable to create window.
		@param title - Caption of window.
	*/
	window(const std::string& title);

	/*! Returns width of window.
		@return Width of window.
	 */
	inline unsigned get_w() { return w; }
	/*! Returns height of window.
		@return Height of window.
	*/
	inline unsigned get_h() { return h; }
};

}

#endif /* GRAPH_WINDOW_HPP */

