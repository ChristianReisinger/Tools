/*
 * helper_functions.hh
 *
 *  Created on: 04.07.2018
 *      Author: reisinger
 */
#include <memory>
#include <vector>
#include <type_traits>
#include <sstream>
#include <stdexcept>

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
int index_of(const std::vector<T>& v, const T elem) {
	return (int) distance(v.begin(), find(v.begin(), v.end(), elem));
}

std::vector<int> parse_unsigned_int_list(char* arg) {
	std::vector<int> ints;

	int val, val_range_first;
	bool err = false;
	bool range = false;
	std::istringstream list_iss(arg);
	while (list_iss >> val && val >= 0) {
		if (range) {
			if (val > val_range_first) {
				for (int rval = val_range_first + 1; rval <= val; ++rval)
					ints.push_back(rval);
			} else {
				err = true;
				break;
			}
			range = false;
		} else
			ints.push_back(val);

		char sep;
		if (list_iss >> sep) {
			if (sep == '-') {
				val_range_first = val;
				range = true;
			} else if (sep != ',') {
				err = true;
				break;
			}
		}
	}
	if (err || list_iss.bad() || !list_iss.eof()) {
		std::ostringstream exc_what_oss;
		exc_what_oss << "invalid list format: " << arg;
		throw std::invalid_argument(exc_what_oss.str());
	}
	return ints;
}

#endif /* INCLUDE_HELPER_FUNCTIONS_HH_ */
