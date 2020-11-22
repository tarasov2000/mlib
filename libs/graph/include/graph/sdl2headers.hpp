#ifndef GRAPH_SDL2HEADERS_HPP
#define GRAPH_SDL2HEADERS_HPP

/**
 * @file sdl2headers.hpp
 *
 * @brief Contains multiplatform including of SDL2 headers.
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

/*! Multiplatform including of SDL2 headers. */
#if defined(__WIN32__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#endif /* GRAPH_SDL2HEADERS_HPP */

