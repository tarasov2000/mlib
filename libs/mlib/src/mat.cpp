#include <mlib/mat.hpp>

namespace mlib {
namespace priv {

void inverse(number** m, unsigned d) {
	// Inversion by LU decomposition
	for (unsigned i = 1; i < d; i++) {
		m[0][i] /= m[0][0];
	}

	for (unsigned i = 1; i < d; i++) {
		for (unsigned j = i; j < d; j++) {
			number sum = 0.0;
			for (unsigned k = 0; k < i; k++) {
				sum += m[j][k] * m[k][i];
			}
			m[j][i] -= sum;
		}
		if (i == d-1) continue;
		for (unsigned j= i + 1; j < d; j++) {
			number sum = 0.0;
		    for (unsigned k = 0; k < i; k++)
		        sum += m[i][k] * m[k][j];
		    m[i][j] = (m[i][j] - sum) / m[i][i];
		}
	}

	// Invert L
	for (unsigned i = 0; i < d; i++) {
	    for (unsigned j = i; j < d; j++) {
	    	number x = 1.0;
	    	if ( i != j ) {
	    		x = 0.0;
	    		for (unsigned k = i; k < j; k++ )
	    			x -= m[j][k] * m[k][i];
	    	}
	    	m[j][i] = x / m[j][j];
		}
	}

	// Invert U
	for (unsigned i = 0; i < d; i++) {
		for (unsigned j = i; j < d; j++) {
			if ( i == j ) continue;
			number sum = 0.0;
			for (unsigned k = i; k < j; k++ )
				sum += m[k][j] * ((i == k) ? 1.0 : m[i][k]);
			m[i][j] = -sum;
		}
	}

	// Final Inversion
	for (unsigned i = 0; i < d; i++) {
		for (unsigned j = 0; j < d; j++) {
			number sum = 0.0;
			for (unsigned k = ((i > j) ? i : j); k < d; k++)
				sum += ((j == k) ? 1.0 : m[j][k]) * m[k][i];
			m[j][i] = sum;
		}
	}
}

}
}
