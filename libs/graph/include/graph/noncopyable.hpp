#ifndef GRAPH_NONCOPYABLE_HPP
#define GRAPH_NONCOPYABLE_HPP

/**
 * @file noncopyable.hpp
 *
 * @brief File stores class for remove copyable
 *		of derived classes.
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

namespace graph {

/*! Class for remove copyable of derived classes. */
class noncopyable {
public:
	/*! Default constructor. */
	noncopyable() = default;
	
	/*! Deleted copy-constructor. */
	noncopyable(const noncopyable&) = delete;
	/*! Deleted copy-assigment */
	noncopyable& operator=(const noncopyable&) = delete; 
};

}

#endif /* GRAPH_NONCOPYABLE_HPP */

