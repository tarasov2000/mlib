#ifndef GRAPH_NONCOPYABLE_HPP
#define GRAPH_NONCOPYABLE_HPP

namespace graph {

class noncopyable {
public:
	noncopyable() = default;

	noncopyable(const noncopyable&) = delete;
	noncopyable& operator=(const noncopyable&) = delete;
};

}

#endif /* GRAPH_NONCOPYABLE_HPP */
