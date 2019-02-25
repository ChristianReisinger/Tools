/*
 * JackknifeAnalyzer.cc
 *
 *  Created on: 22.02.2019
 *      Author: reisinger
 */

#include <map>
#include <vector>
#include <exception>
#include <cmath>
#include <type_traits>
#include <helper_functions.hh>
#include <JackknifeAnalyzer.hh>

template<typename K, typename T>
JackknifeAnalyzer<K, T>::JackknifeAnalyzer() {
	init();
}

template<typename K, typename T>
JackknifeAnalyzer<K, T>::JackknifeAnalyzer(const K& Xkey, const std::vector<T>& Xsamples) {
	init();
	resample(Xkey, Xsamples);
}

template<typename K, typename T>
void JackknifeAnalyzer<K, T>::add_resampled(const K& Xkey, const std::vector<T>& Xjackknife_samples) {
	if (verify_X(Xkey, Xjackknife_samples))
		Xs_reduced_samples[Xkey] = Xjackknife_samples;
}

template<typename K, typename T>
void JackknifeAnalyzer<K, T>::resample(const K& Xkey, const std::vector<T>& Xsamples) {
	if (verify_X(Xkey, Xsamples)) {
		T sum_samples = 0;
		for (T d : Xsamples)
			sum_samples += d;

		std::vector<T> red_samples;
		for (T d : Xsamples)
			red_samples.push_back((sum_samples - d) / ((T) (N_samples - 1)));

		Xs_reduced_samples[Xkey] = red_samples;
	}
}

template<typename K, typename T>
template<typename ... Ks, typename ... Ts>
void JackknifeAnalyzer<K, T>::add_function(const K& Fkey, T (*F)(Ts...), const Ks& ... F_arg_keys) {
	static_assert(and_type<std::is_convertible<Ks, K>::value ...>::value , "JackknifeAnalyzer::add_function invalid key type");
	static_assert(and_type<std::is_convertible<Ts, T>::value ...>::value , "JackknifeAnalyzer::add_function invalid data type");

	if (Xs_reduced_samples.count(Fkey) == 0) {
		std::vector<T> F_jackknife_samples;
		for (int i = 0; i < N_samples; ++i)
			F_jackknife_samples.push_back(F(Xs_reduced_samples.at(F_arg_keys)[i]...));
		Xs_reduced_samples[Fkey] = F_jackknife_samples;
	}
}

template<typename K, typename T>
void JackknifeAnalyzer<K, T>::jackknife(const K& Xkey, T& mu_X, T& sigma_X) {
	mu_X = 0;
	for (T d : Xs_reduced_samples[Xkey])
		mu_X += d;
	mu_X /= (T) N_samples;

	sigma_X = 0;
	for (T d : Xs_reduced_samples[Xkey])
		sigma_X += pow(d - mu_X, (T) 2);
	sigma_X = sqrt((((T) (N_samples - 1)) / ((T) N_samples)) * sigma_X);
}



// ************************************** private **************************************

/**
 * initialize
 */
template<typename K, typename T>
void JackknifeAnalyzer<K, T>::init() {
	static_assert(std::is_arithmetic<T>::value, "JackknifeAnalyzer data type is not arithmetic");
	N_samples = 0;
}

/**
 * Ensure equal and > 1 number of samples for all variables, otherwise an exception is thrown.
 * Return true if number of samples is equal to existing data and data with the key Xkey does not exist, false otherwise.
 */
template<typename K, typename T>
bool JackknifeAnalyzer<K, T>::verify_X(const K& Xkey, const std::vector<T>& Xsamples) {
	if (Xs_reduced_samples.count(Xkey))
		return false;

	if (N_samples == 0) {
		if (Xsamples.size() > 1)
			N_samples = Xsamples.size();
		else
			throw std::runtime_error("trying to add dataset with less than 2 samples.");
	} else if (Xsamples.size() != N_samples)
		throw std::runtime_error("trying to add dataset with different number of samples than already existing ones.");

	return true;
}
