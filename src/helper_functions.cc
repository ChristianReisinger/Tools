/*
 * helper_functions.cc
 *
 *  Created on: 28.02.2019
 *      Author: reisinger
 */

#include <vector>
#include <sstream>
#include <helper_functions.hh>

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
