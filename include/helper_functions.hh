#include <memory>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <iomanip>

#ifndef INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_HELPER_HELPER_FUNCTIONS_HH_
#define INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_HELPER_HELPER_FUNCTIONS_HH_

namespace de_uni_frankfurt_itp {
namespace reisinger {
namespace tools {
namespace helper {

/**
 * and_type::value is true if all template arguments are true, false otherwise.
 */
template<bool...> struct and_type;
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
int index_of(const std::vector<T>& v, const T& elem) {
	return (int) std::distance(v.begin(), std::find(v.begin(), v.end(), elem));
}

template<typename T>
bool contains(const std::vector<T>& v, const T& elem) {
	return std::find(v.begin(), v.end(), elem) != v.end();
}

std::vector<int> parse_unsigned_int_list(const char* arg);

template<typename Rep, typename Period>
std::string timestamp(std::chrono::duration<Rep, Period> duration) {
	std::ostringstream timestamp_oss;
	timestamp_oss << std::setfill('0');

	const auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
	duration -= hours;
	timestamp_oss << std::setw(2) << hours.count() << ':';

	const auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
	duration -=minutes;
	timestamp_oss << std::setw(2) << minutes.count() << ':';

	const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
	timestamp_oss << std::setw(2) << seconds.count();

	return timestamp_oss.str();
}

}
}
}
}

#endif
