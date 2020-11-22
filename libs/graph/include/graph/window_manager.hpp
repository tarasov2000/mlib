#ifndef GRAPH_WINDOW_MANAGER_HPP
#define GRAPH_WINDOW_MANAGER_HPP

#include <map>

#include <graph/noncopyable.hpp>

namespace graph {
	class window;
	class window_manager : private noncopyable {
		friend class window;
		std::map<unsigned, window*> m_windows;

		window_manager() = default;
	public:
		static window_manager& get_instance();

		bool poll_events();
	};
}

#define POLL_EVENTS (graph::window_manager::get_instance().poll_events())

#endif /* GRAPH_WINDOW_MANAGER_HPP */
