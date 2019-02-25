/*
 * helper_functions.hh
 *
 *  Created on: 04.07.2018
 *      Author: reisinger
 */
#include <memory>
#include <vector>
#include <type_traits>

#ifndef INCLUDE_HELPER_FUNCTIONS_HH_
#define INCLUDE_HELPER_FUNCTIONS_HH_

/**
 * and_type::value is true if all template arguments are true, false otherwise.
 */
template<bool ...> struct and_type;
template<bool ... bs> struct and_type<false, bs...> : std::false_type {
};
template<bool ... bs> struct and_type<true, bs...> : and_type<bs...> {
};
template<> struct and_type<> : std::true_type {
};

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique(Args&& ...args) {
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template<typename T>
int indexOf(const std::vector<T>& v, const T elem) {
	return (int) distance(v.begin(), find(v.begin(), v.end(), elem));
}

#endif /* INCLUDE_HELPER_FUNCTIONS_HH_ */
