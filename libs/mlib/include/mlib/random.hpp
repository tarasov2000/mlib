#ifndef MLIB_RANDOM_HPP
#define MLIB_RANDOM_HPP

#include <cstdlib>
#include <ctime>

namespace mlib
{
	namespace random
	{
		void init() {
			srand(static_cast<unsigned int>(time(nullptr)));
		}

		template <typename T>
		T next() {
			return 1.0 - (static_cast<float>(rand()) / RAND_MAX) * 2.0;
		}

	}
}

#endif /* MLIB_RANDOM_HPP */
