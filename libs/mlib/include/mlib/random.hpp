#ifndef MLIB_RANDOM_HPP
#define MLIB_RANDOM_HPP

#include <cstdlib>
#include <ctime>

namespace mlib
{
	/*! Class for generating random numbers. */
	class random
	{
	public:
		/*! Initialize random generator. */
		static void init() {
			srand(static_cast<unsigned int>(time(nullptr)));
		}

		/*! Generate next random number. */
		template <typename T>
		static T next() {
			return 1.0 - (static_cast<float>(rand()) / RAND_MAX) * 2.0;
		}

	};
}

#endif /* MLIB_RANDOM_HPP */
