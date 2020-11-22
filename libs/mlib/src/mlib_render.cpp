#include <mlib/mlib_render.hpp>

#include <graph/window.hpp>

#include <mlib/buffer.hpp>

namespace mlib {

mlib_render::mlib_render(graph::window& win, float sw, float sh)
	: render(win),
	  w(win.get_w()),
	  h(win.get_h()),
	  sx(w / sw),
	  sy(h / 2 / sh) { }

void mlib_render::draw(const buffer& b) {
	for (size i = 0; i + 1 < BUFFER_SIZE; i++) {
		line(i * sx,
			h / 2 - (b[i] * sy),
			i * sx + sx,
			h / 2 - (b[i +1] * sy));
	}
}

}
