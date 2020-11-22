#ifndef MLIB_POLYNOM_HPP
#define MLIB_POLYNOM_HPP

#include <mlib/buffer.hpp>
#include <mlib/vec.hpp>

namespace mlib {
	namespace priv {
		void polynom(number* buff, number* v, unsigned d);
	}

	template <unsigned D>
	void polynom(buffer& buff, vec<D>& v) {
		priv::polynom(&(buff[0]), &(v[0]), D);
	}
}

#endif /* MLIB_POLYNOM_HPP */
