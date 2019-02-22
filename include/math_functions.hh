/*
 * math_function.hh
 *
 *  Created on: 11.10.2018
 *      Author: reisinger
 */

#include <cmath>

#ifndef INCLUDE_MATH_FUNCTIONS_HH_
#define INCLUDE_MATH_FUNCTIONS_HH_

namespace math_functions {

int gcd(int a, int b) {
	a = std::abs(a);
	b = std::abs(b);
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int sgn(double d) {
	return (d > 0) - (d < 0);
}

int sgn(int i) {
	return (i > 0) - (i < 0);
}

}

#endif /* INCLUDE_MATH_FUNCTIONS_HH_ */
