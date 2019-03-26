/*
 * math_function.cc
 *
 *  Created on: 22.03.2019
 *      Author: Shiwayari
 */

#include <cmath>
#include <vector>
#include <utility>

#include <math_functions.hh>

int math_functions::gcd(int a, int b) {
	a = std::abs(a);
	b = std::abs(b);
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

double math_functions::fit_constant(std::vector<std::pair<double, double> > pts_mu_sigma) {
	double fit = 0.0;
	double norm = 0.0;
	for (auto pt : pts_mu_sigma) {
		double sigma_sq = std::pow(pt.second, 2.0);
		norm += 1.0 / sigma_sq;
		fit += pt.first / sigma_sq;
	}
	return fit / norm;
}

double math_functions::fit_constant(std::vector<std::pair<double, double> > pts_mu_sigma, double& red_chi_sq) {
	double fit = fit_constant(pts_mu_sigma);

	int N = pts_mu_sigma.size();
	red_chi_sq = 0.0;
	for (auto pt : pts_mu_sigma)
		red_chi_sq += std::pow(pt.first - fit, 2.0) / std::pow(pt.second, 2.0);
	red_chi_sq /= (double) N - 1.0;

	return fit;
}
