#ifndef MLIB_VEC_HPP
#define MLIB_VEC_HPP

#include <ostream>

#include <mlib/buffer.hpp>

namespace mlib {

	/*! Class represent vector of data with size `D`. */
	template <unsigned D>
	class vec {
	
		/*! Data of vector. */
		number m_data[D];
	public:
	
		/*! Default variant of constructor. */
		vec() = default;
		
		/*! Constructor generates data from 3 buffers.
			@param temp - Template buffer.
			@param y - Buffer with `y`.
			@param t - Buffer with `t`.
		*/
		vec(buffer& temp, const buffer& y, const buffer& t) {
			for (unsigned i = 0; i < D; i++) {
				m_data[i] = temp.copy(t).pow(D - 1 - i)
						.foreach(y, [](number ey, number et) {
					return ey * et;
				}).sum();
			}
		}
		
		/*! Indexer. */
		inline number& operator [](unsigned i) {
			return m_data[i];
		}
		
		/*! Constant indexer. */
		inline number operator [](unsigned i) const {
			return m_data[i];
		}
	};
}

/*! Overloading operator for output vector on `std::cout`. */
template <unsigned D>
std::ostream& operator <<(std::ostream& os, const mlib::vec<D>& v) {
	os << "[ " << v[0];
	for (unsigned i = 1; i < D; i++) {
		os << ", " << v[i];
	}
	return os << " ]";
}

#endif /* MLIB_VEC_HPP */

