#ifndef GRAPH_SDL2_HPP
#define GRAPH_SDL2_HPP

#include <mutex>

#include <graph/noncopyable.hpp>

namespace graph {

class sdl2 : protected noncopyable {
	static volatile unsigned long long counter;

	std::mutex m_mutex;
public:
	sdl2();
	~sdl2();
};

}

#endif /* GRAPH_SDL2_HPP */
