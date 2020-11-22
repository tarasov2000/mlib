/**
 * @file main.cpp
 *
 * @brief File with `main` function.
 *
 * @author Ihor Tarasov
 * Contact: mov.ax.38@gmail.com
 *
 */

#include <iostream>

#include <cmath>

#include <mlib/mlib.hpp>

#include <graph/graph.hpp>

using namespace mlib;
using namespace graph;

int main() {
	random::init();
	window w("MLib");
	mlib_render r(w, BUFFER_SIZE, 1);

	buffer t;

	t.fori([] (size i) { return i; });
	std::cout << "t = " << t << std::endl;

	buffer y0(t);
	y0.foreach([] (number e) { return std::cos(2.0f * PI * 1 * e / number(BUFFER_SIZE)); });
	y0.foreach([] (number e) { return e + 0.5 * random::next<number>(); });
	std::cout << "y0 = " << y0 << std::endl;


	buffer L;

	buffer tmp;
	L.fori([&y0, &tmp] (size k) {
		if (k == 0) {
			return (1.0 / std::sqrt(BUFFER_SIZE)) * y0.sum();
		} else {
			return tmp.fori([&y0, k](size m) -> number {
				return y0[m] * std::cos(((2.0 * m + 1.0) * k * PI) / (2.0 * BUFFER_SIZE));
			}).sum() * std::sqrt(2.0 / BUFFER_SIZE);
		}
	});
	std::cout << "L = " << L << std::endl;

	size counter = 0;
	buffer R;
	R.foreach([] (number) { return 0; });
	bool finished = false;

	while (POLL_EVENTS) {
		r.color(0, 0, 255);
		r.draw(y0);

		if (!finished) {
			buffer X;
			X.fori([&L, &tmp, counter] (size m) {
				return (L[counter] * std::cos(((2.0 * m + 1) * counter * PI) / (2.0 * BUFFER_SIZE)));
			});

			//std::cout << "X = " << X << std::endl;
			r.color(100, 0, 0);
			r.draw(X);

			R.foreach(X, [](number ex, number er) { return  ex + er;});
		}

		tmp.fori([&R, &L] (std::size_t i) {
			return (1.0 / std::sqrt(BUFFER_SIZE)) * L[0] + std::sqrt(2.0 / BUFFER_SIZE) * R[i];
		});

		r.color(255, 255, 255);
		r.draw(tmp);

		r.display(50);

		counter++;
		if (counter == BUFFER_SIZE) {
			counter = 0;
			finished = true;
		}
	}
	return 0;
}

