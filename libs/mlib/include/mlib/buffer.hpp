#ifndef MLIB_BUFFER_HPP
#define MLIB_BUFFER_HPP

#include <ostream>
#include <functional>
#include <mlib/types.hpp>

namespace mlib {
	class buffer {
		number* m_data;
	public:
		buffer();
		~buffer();

		buffer& copy(const buffer& b);

		buffer(const buffer& b);
		buffer& operator=(const buffer& b);

		buffer(buffer&& b) noexcept;
		buffer& operator=(buffer&& b) noexcept;

		inline number& operator [](size i) {
			return m_data[i];
		}

		inline number operator [](size i) const {
			return m_data[i];
		}

		buffer& foreach(std::function<number(number)>);
		buffer& foreach(const buffer& src, std::function<number(number, number)>);
		buffer& fori(std::function<number(size)>);
		buffer& fori(const buffer& src, std::function<number(number, size)>);
		buffer& pow(unsigned s);
		number sum();
	};

	std::ostream& operator <<(std::ostream& os, const mlib::buffer& d);
}

#endif /* MLIB_BUFFER_HPP */
