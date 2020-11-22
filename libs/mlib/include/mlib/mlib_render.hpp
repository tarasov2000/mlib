#ifndef MLIB_MLIB_RENDER_HPP
#define MLIB_MLIB_RENDER_HPP

#include <graph/noncopyable.hpp>
#include <graph/render.hpp>
#include <graph/window.hpp>

namespace mlib {
	class buffer;
	
	/*! Class created for drawings buffers. */
	class mlib_render : public graph::render {
		/*! Width and height of render zone. */
		unsigned w, h;
		
		/*! Scale x and y. */
		float sx, sy;
	public:
		/*! Constructor initializes renderer with maximum width and height.
			@param w - Widnow for render.
			@param sw - Maximum width of function.
			@param sh - Maximum height of function.
		*/
		mlib_render(graph::window& w, float sw, float sh);

		/*! Draws buffer of screen as function graphic.
			@param b - Buffer for outputing.
		*/
		void draw(const buffer& b);
	};
}

#endif /* MLIB_MLIB_RENDER_HPP */

