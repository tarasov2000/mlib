#include <mlib/buffer.hpp>

#include <algorithm>
#include <cmath>

namespace mlib {

buffer::buffer()
	: m_data(new number[BUFFER_SIZE]) { }

buffer::~buffer() {
	delete[] m_data;
}

buffer& buffer::copy(const buffer& b) {
	std::copy(b.m_data, b.m_data + BUFFER_SIZE,
		m_data);
	return *this;
}

buffer::buffer(const buffer& b)
	: buffer() {
	copy(b);
}

buffer& buffer::operator=(const buffer& b) {
	if (m_data != b.m_data) { return *this; }
	if (m_data) { delete[] m_data; }
	return copy(b);
}

buffer::buffer(buffer&& b) noexcept
	: m_data(b.m_data) {
	b.m_data = nullptr;
}

buffer& buffer::operator=(buffer&& b) noexcept {
	if (m_data != b.m_data) {
		if (m_data) { delete[] m_data; }
		m_data = b.m_data;
		b.m_data = nullptr;
	}
	return *this;
}

buffer& buffer::foreach(std::function<number(number)> cb) {
	for (size i = 0; i < BUFFER_SIZE; i++) {
		m_data[i] = cb(m_data[i]);
	}
	return *this;
}

buffer& buffer::foreach(const buffer& src, std::function<number(number, number)> cb) {
	for (size i = 0; i < BUFFER_SIZE; i++) {
		m_data[i] = cb(src.m_data[i], m_data[i]);
	}
	return *this;
}

buffer& buffer::fori(std::function<number(size)> cb) {
	for (size i = 0; i < BUFFER_SIZE; i++) {
		m_data[i] = cb(i);
	}
	return *this;
}

buffer& buffer::fori(const buffer& src, std::function<number(number, size)> cb) {
	for (size i = 0; i < BUFFER_SIZE; i++) {
		m_data[i] = cb(src.m_data[i], i);
	}
	return *this;
}

buffer& buffer::pow(unsigned s) {
	for (size i = 0; i < BUFFER_SIZE; i++) {
		m_data[i] = std::pow(m_data[i], s);
	}
	return *this;
}

number buffer::sum() {
	number acc = m_data[0];
	for (size i = 1; i < BUFFER_SIZE; i++) {
		acc += m_data[i];
	}
	return acc;
}

std::ostream& operator <<(std::ostream& os, const mlib::buffer& d) {
	os << "[ ";
	for (size i = 0; i + 1 < BUFFER_SIZE; i++ ) {
		os << d[i] << ", ";
	}
	return os << d[BUFFER_SIZE - 1] << " ]";
}

}
