#ifndef MLIB_VEC_HPP
#define MLIB_VEC_HPP

#include <ostream>

#include <mlib/buffer.hpp>

namespace mlib {
	template <unsigned D>
	class vec {
		number m_data[D];
	public:
		vec() = default;

		vec(buffer& temp, const buffer& y, const buffer& t) {
			for (unsigned i = 0; i < D; i++) {
				m_data[i] = temp.copy(t).pow(D - 1 - i)
						.foreach(y, [](number ey, number et) {
					return ey * et;
				}).sum();
			}
		}

		inline number& operator [](unsigned i) {
			return m_data[i];
		}

		inline number operator [](unsigned i) const {
			return m_data[i];
		}
	};
}

template <unsigned D>
std::ostream& operator <<(std::ostream& os, const mlib::vec<D>& v) {
	os << "[ " << v[0];
	for (unsigned i = 1; i < D; i++) {
		os << ", " << v[i];
	}
	return os << " ]";
}

#endif /* MLIB_VEC_HPP */
