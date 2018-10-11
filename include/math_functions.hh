/*
 * math_function.hh
 *
 *  Created on: 11.10.2018
 *      Author: reisinger
 */

#ifndef INCLUDE_MATH_FUNCTIONS_HH_
#define INCLUDE_MATH_FUNCTIONS_HH_

#include <cmath>

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

}

#endif /* INCLUDE_MATH_FUNCTIONS_HH_ */
