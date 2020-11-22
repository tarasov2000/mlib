#ifndef MLIB_MLIB_RENDER_HPP
#define MLIB_MLIB_RENDER_HPP

#include <graph/noncopyable.hpp>
#include <graph/render.hpp>
#include <graph/window.hpp>

namespace mlib {
	class buffer;

	class mlib_render : public graph::render {
		unsigned w, h;
		float sx, sy;
	public:
		mlib_render(graph::window&, float sw, float sh);

		void draw(const buffer&);
	};
}

#endif /* MLIB_MLIB_RENDER_HPP */
