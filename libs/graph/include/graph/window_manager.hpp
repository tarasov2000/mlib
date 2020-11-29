#ifndef GRAPH_WINDOW_MANAGER_HPP
#define GRAPH_WINDOW_MANAGER_HPP

/**
 * @file window_manager.hpp
 *
 * @brief Stores definition of window_manager class.
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

#include <map>
#include <mutex>

#include <graph/noncopyable.hpp>

namespace graph {
	class window;
	
	/*! Singletone class for storing all windows. */
	class window_manager : private noncopyable {
		friend class window;
		
		/*! Key-value storage for window id and pointers to window.*/
		std::map<unsigned, window*> m_windows;
		
		/*! Mutex for creating windows in differend threads. */
		std::mutex m_mutex;

		/*! Private default constructor. */
		window_manager() = default;
	public:
	
		/*! Static method for creating instance. */
		static window_manager& get_instance();

		/*! Reseive all events for all windows.
			@return if `false` then all windows was closed overwise return true.
		*/
		bool poll_events();
	};
}

/*! Preprocessor directive for polling events. */
#define POLL_EVENTS (graph::window_manager::get_instance().poll_events())

#endif /* GRAPH_WINDOW_MANAGER_HPP */

