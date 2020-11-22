#ifndef GRAPH_RENDER_HPP
#define GRAPH_RENDER_HPP

/**
 * @file render.hpp
 *
 * @brief Stores definition of render class.
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

#include <graph/noncopyable.hpp>

struct SDL_Renderer;

namespace graph {
	class window;
	
	/*! Represents renderer for window. */
	class render : protected noncopyable {
	
		/*! Pointer to SDL2 renderer class. */
		SDL_Renderer* m_renderer;
	public:
	
		/*! Create renderer for window.
			Can throws `runtime_error` if unable to create render.
			@param w - Window for renderer.
		*/ 
		explicit render(window& w);
		
		/*! Destroys renderer. */
		~render();

		/*! Set the render color in RGB.
			@param r - R channel of RGB.
			@param g - G channel of RGB.
			@param b - B channel of RGB.
		*/
		void color(unsigned char r, unsigned char g, unsigned char b);
		
		/*! Draws the line on screen from `(x1, y1)` to `(x2, y2)`.
			@param x1 - x of start point.
			@param y1 - y of start point.
			@param x2 - x of end point.
			@param y2 - y of end point.
		*/
		void line(float x1, float y1, float x2, float y2);
		
		/*! Swap buffers and sleep `ms` milliseconds.
			@param ms - Milliseconds to sleep after swapping.
		*/
		void display(unsigned ms);
	};

}

#endif /* GRAPH_RENDER_HPP */

