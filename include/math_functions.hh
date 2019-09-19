#include <cmath>
#include <vector>
#include <utility>

#ifndef INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_MATH_MATH_FUNCTIONS_HH_
#define INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_MATH_MATH_FUNCTIONS_HH_

namespace de_uni_frankfurt_itp {
namespace reisinger {
namespace tools {
namespace math {

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
}
}
}

#endif
