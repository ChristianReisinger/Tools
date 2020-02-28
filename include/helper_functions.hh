#include <memory>
#include <vector>
#include <map>
#include <set>
#include <type_traits>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <string>
#include <functional>
#include <iterator>

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

bool ends_with(const std::string& s, const std::string& suffix);

std::vector<std::string> split(const std::string& str, const std::string& delim, bool remove_empty = false);

template<typename Rep, typename Period>
std::string timestamp(std::chrono::duration<Rep, Period> duration) {
	std::ostringstream timestamp_oss;
	timestamp_oss << std::setfill('0');

	const auto hours = std::chrono::duration_cast<std::chrono::hours>(duration);
	duration -= hours;
	timestamp_oss << std::setw(2) << hours.count() << ':';

	const auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
	duration -= minutes;
	timestamp_oss << std::setw(2) << minutes.count() << ':';

	const auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
	timestamp_oss << std::setw(2) << seconds.count();

	return timestamp_oss.str();
}

namespace {
template<typename Function, typename ...Args>
void do_nest_for(std::vector<int>& is, std::size_t ii, const std::vector<std::pair<int, int> >& index_limits,
		Function f, Args&& ...args) {
	if (ii < is.size()) {
		for (is[ii] = index_limits[ii].first; is[ii] < index_limits[ii].second; ++is[ii])
			do_nest_for(is, ii + 1, index_limits, f, std::forward<Args>(args)...);
	} else
		f(is, std::forward<Args>(args)...);
}
}

/**
 * @param f	a function void f(const std::vector<int>&, Args ...)
 */
template<typename Function, typename ...Args>
void nest_for(const std::vector<std::pair<int, int> >& index_limits,
		Function f, Args&& ...args) {
	static_assert(std::is_convertible<Function, std::function<void(const std::vector<int>&, decltype(args)...)> >::value,
			"nest_for: invalid function");
	if (index_limits.empty())
		throw std::invalid_argument("nest_for: empty index_limits");

	std::vector<int> is(index_limits.size());
	do_nest_for(is, 0, index_limits, f, std::forward<Args>(args)...);
}

template<typename Key, typename Value, typename ...Other>
std::set<Key> keyset(const std::map<Key, Value, Other...>& m) {
	std::set<Key> keyset;
	std::transform(m.begin(), m.end(),
			std::inserter(keyset, keyset.begin()),
			[](const std::pair<Key, Value>& p) {
				return p.first;
			});
	return keyset;
}

}
}
}
}

#endif
