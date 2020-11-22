#ifndef GRAPH_SDL2_HPP
#define GRAPH_SDL2_HPP

/**
 * @file sdl2.hpp
 *
 * @brief Stores definition of class sdl2.
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

#include <mutex>

#include <graph/noncopyable.hpp>

namespace graph {

/*! Class created for RAII wrapping of SDL_Init() and SDL_Quit() */
class sdl2 : protected noncopyable {
	
	/*! Counter for count created instances. */
	static volatile unsigned long long counter;
	
	/*! Mutex for locking changes of counter. */
	std::mutex m_mutex;
public:

	/*! Initialize SDL2 if not initialized.
		Can throws `runtime_error` if unable to initialize SDL2.
	*/
	sdl2();
	
	/*! Deinitialize SDL2. */
	~sdl2();
};

}

#endif /* GRAPH_SDL2_HPP */

