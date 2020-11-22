#ifndef GRAPH_RENDER_HPP
#define GRAPH_RENDER_HPP

#include <graph/noncopyable.hpp>

struct SDL_Renderer;

namespace graph {
	class window;

	class render : protected noncopyable {
		SDL_Renderer* m_renderer;
	public:
		explicit render(window&);
		~render();

		void color(unsigned char r, unsigned char g, unsigned char b);
		void line(float x1, float y1, float x2, float y2);
		void display(unsigned ms);
	};

}

#endif /* GRAPH_RENDER_HPP */
