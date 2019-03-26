/*
 * math_function.hh
 *
 *  Created on: 11.10.2018
 *      Author: reisinger
 */

#include <cmath>
#include <vector>
#include <utility>

#ifndef INCLUDE_MATH_FUNCTIONS_HH_
#define INCLUDE_MATH_FUNCTIONS_HH_

namespace math_functions {

int gcd(int a, int b);

inline int sgn(double d) {
	return (d > 0) - (d < 0);
}

inline int sgn(int i) {
	return (i > 0) - (i < 0);
}

/**
 * Fit a constant to the given data points. Optionally compute reduced chi squared.
 * Does not compute an error (use e.g. a jackknife analysis).
 */
double fit_constant(std::vector<std::pair<double, double> > pts_mu_sigma);
double fit_constant(std::vector<std::pair<double, double> > pts_mu_sigm, double& red_chi_sq);

}

#endif /* INCLUDE_MATH_FUNCTIONS_HH_ */
