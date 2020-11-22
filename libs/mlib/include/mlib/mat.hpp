#ifndef MLIB_MAT_HPP
#define MLIB_MAT_HPP

#include <ostream>

#include <mlib/buffer.hpp>
#include <mlib/vec.hpp>

namespace mlib {
	namespace priv {
		void inverse(number** m, unsigned d);
	}

	template <unsigned D>
	class mat {
		number m_data[D][D];
	public:
		mat(const buffer& b) {
			number arr[D * 2 -1];
			buffer temp;
			for (unsigned i = 0; i + 1 < D * 2; i++) {
				arr[i] = (temp = b).pow(i).sum();
			}
			unsigned y_start = D * 2 - 2;
			for (unsigned y = 0; y < D; y++) {
				unsigned x_start = y_start--;
				for (unsigned x = 0; x < D; x++) {
					m_data[y][x] = arr[x_start--];
				}
			}
		}

		inline number* operator [](unsigned y) {
			return m_data[y];
		}

		inline const number* operator [](unsigned y) const {
			return m_data[y];
		}

		void inverse() {
			priv::inverse(m_data, D);
		}

	};

	template <unsigned D>
	mlib::vec<D> operator *(const mlib::mat<D>& m, const mlib::vec<D>& v) {
		mlib::vec<D> r;
		//            0
		//            1
		//            2
		//            3
		//0  1  2  3
		//4  5  6  7
		//8  9  10 11
		//12 13 14 15
		for (unsigned y = 0; y < D; y++) {
			number tmp = 0;
			for (unsigned x = 0; x < D; x++) {
				tmp += v[x] * m[y][x];
			}
			r[y] = tmp;
		}
		return r;
	}

	template <unsigned D>
	std::ostream& operator <<(std::ostream& os, const mlib::mat<D>& m) {
		os << "[ " << std::endl;
		for (unsigned y = 0; y < D; y++) {
			os << "[ ";
			for (unsigned x = 0; x < D; x++) {
				os << m[y][x] <<
						(x == D - 1 ? (y == D - 1 ? "" : " ]") : ", ");
			}
			y == D - 1 ? (os << " ]" << std::endl << "]") :
					(os << " ]," << std::endl);
		}
		return os;
	}
}

#endif /* MLIB_MAT_HPP */
