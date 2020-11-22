#include <mlib/polynom.hpp>

#include <cmath>

namespace mlib {
namespace priv {

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
