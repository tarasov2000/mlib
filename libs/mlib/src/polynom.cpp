/**
 * @file polynom.cpp
 *
 * @brief Stores realization of some methods from polynom
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

#include <mlib/polynom.hpp>

#include <cmath>

namespace mlib {
namespace priv {

/*! Generating polynom. */
void polynom(number* buff, number* v, unsigned d) {
	for (size i = 0; i < BUFFER_SIZE; i++) {
		number res = 0;
		for (unsigned j = 0; j < d; j++) {
			res += v[j] * std::pow(buff[i], d - 1 - j);
		}
		buff[i] = res;
	};
}

}
}

