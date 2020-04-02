#include <vector>
#include <sstream>
#include <helper_functions.hh>
#include <regex>

namespace de_uni_frankfurt_itp {
namespace reisinger {
namespace tools {
namespace helper {

std::vector<int> parse_unsigned_int_list(const char* arg) {
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

bool ends_with(const std::string& str, const std::string& suffix) {
	return str.size() >= suffix.size() && str.substr(str.size() - suffix.size()) == suffix;
}

std::vector<std::string> split(const std::string& str, const std::string& delim, bool remove_empty) {
	std::vector<std::string> tokens;

	for (size_t start = 0, end; start < str.length(); start = end + delim.length()) {
		size_t pos = str.find(delim, start);
		end = pos != std::string::npos ? pos : str.length();

		const std::string token = str.substr(start, end - start);
		if (!remove_empty || !token.empty())
			tokens.push_back(token);
	}

	if (!remove_empty && (str.empty() || ends_with(str, delim)))
		tokens.push_back("");

	return tokens;
}

std::vector<std::string> tokenize(const std::string& str, const std::string& delim_regex) {
	std::vector<std::string> tokens;

	std::regex delim(delim_regex);
	std::sregex_token_iterator it(str.begin(), str.end(), delim, -1);
	for (; it != std::sregex_token_iterator(); ++it)
		if (!it->str().empty())
			tokens.emplace_back(it->str());

	return tokens;
}

}
}
}
}
