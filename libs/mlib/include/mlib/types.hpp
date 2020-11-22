#ifndef MLIB_TYPES_HPP
#define MLIB_TYPES_HPP

#include <cstdlib>

namespace mlib {

	using number = long double;
	using size = std::size_t;

	constexpr size BUFFER_SIZE = 256;
	constexpr number PI = 3.14159265359;
}

#endif /* MLIB_TYPES_HPP */
