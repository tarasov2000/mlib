/**
 * @file render.cpp
 *
 * @brief Stores some realization of class render methods.
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

#include <graph/render.hpp>

#include <stdexcept>
#include <string>

#include <graph/sdl2headers.hpp>
#include <graph/window.hpp>

using namespace std;

namespace graph {

/*! Creating renderer using window. */
render::render(window& w)
	: m_renderer(SDL_CreateRenderer(w.m_window,
			0,
			SDL_RENDERER_SOFTWARE))	{
	if (!m_renderer) {
		throw runtime_error("Unable to create renderer. SDL_Error: " +
				string(SDL_GetError()));
	}
	SDL_RenderSetLogicalSize(m_renderer, w.w, w.h);
}

/*! Delete renderer*/
render::~render() {
	SDL_DestroyRenderer(m_renderer);
}

/*! Using `SDL_SetRenderDrawColor` to set color for drawing. */
void render::color(unsigned char r, unsigned char g, unsigned char b) {
	SDL_SetRenderDrawColor(m_renderer, r, g, b, 255);
}

/*! Drawing line on the screen. */
void render::line(float x1, float y1, float x2, float y2) {
	SDL_RenderDrawLineF(m_renderer, x1, y1, x2, y2);
}

/*! Swap buffers and clear screen. Don't forget about sleep `ms` milliseconds.*/
void render::display(unsigned ms) {
	SDL_RenderPresent(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
	SDL_Delay(ms);
}

}

