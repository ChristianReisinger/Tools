#include <vector>
#include <initializer_list>
#include <utility>
#include <stdexcept>

#ifndef INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_DICT_HH_
#define INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_DICT_HH_

namespace de_uni_frankfurt_itp {
namespace reisinger {
namespace tools {

template<typename L, typename R>
class Dict {
	std::vector<L> m_l;
	std::vector<R> m_r;

public:

	Dict(const std::initializer_list<std::pair<L, R> >& ilist) {
		static_assert(!std::is_same<L, R>::value, "Dict of equal types");

		const auto num_elems = ilist.size();
		m_l.reserve(num_elems);
		m_r.reserve(num_elems);

		for (const auto& [l, r] : ilist) {
			m_l.push_back(l);
			m_r.push_back(r);
		}
	}

	const L& operator[](const R& right) const {
		for (std::size_t i = 0; i < m_r.size(); ++i)
			if (m_r[i] == right)
				return m_l[i];
		throw std::out_of_range("right does not exist");
	}

	const R& operator[](const L& left) const {
		for (std::size_t i = 0; i < m_l.size(); ++i)
			if (m_l[i] == left)
				return m_r[i];
		throw std::out_of_range("left does not exist");
	}

	auto lbegin() const {
		return m_l.cbegin();
	}

	auto rbegin() const {
		return m_r.cbegin();
	}
};

}
}
}

#endif
