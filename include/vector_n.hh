#ifndef INCLUDE_VECTOR_N_HH_
#define INCLUDE_VECTOR_N_HH_

#include <vector>
#include <algorithm>

template<std::size_t dim, typename T>
class sub_vector_n {
	typename std::vector<T>::iterator it;
	std::vector<std::size_t> sizes;

public:
	sub_vector_n() = default;

	sub_vector_n(typename std::vector<T>::iterator sub_it, const std::vector<std::size_t>& sub_sizes) :
			it(sub_it), sizes(sub_sizes) {
	}

	sub_vector_n<dim - 1, T> operator[](unsigned int i) {
		std::vector<std::size_t> sub_sizes(sizes.size() - 1);
		std::copy(std::begin(sizes) + 1, std::end(sizes), std::begin(sub_sizes));
		unsigned int sub_elems = 1;
		for (auto s : sub_sizes)
			sub_elems *= s;
		return sub_vector_n<dim - 1, T>(it + sub_elems, sub_sizes);
	}
};

template<typename T>
class sub_vector_n<1, T> {

	typename std::vector<T>::iterator it;
	std::vector<std::size_t> sizes;

public:

	sub_vector_n() = default;

	sub_vector_n(typename std::vector<T>::iterator sub_it, const std::vector<std::size_t>& sub_sizes) :
			it(sub_it), sizes(sub_sizes) {
	}

	T& operator[](unsigned int i) {
		return *(it + i);
	}
};

template<std::size_t dim, typename T>
class vector_n {

	std::vector<T> v;
	sub_vector_n<dim, T> sub_v;

public:

	vector_n() {
		std::vector<std::size_t> sizes(dim, 1);
		sub_v = sub_vector_n<dim, T>(std::begin(v), sizes);
	}

	vector_n(std::initializer_list<std::size_t> sizes_initlist, const T& value = T()) {
		unsigned int elems = 1;
		for (auto s : sizes_initlist)
			elems *= s;
		v = std::vector<T>(elems, value);

		std::vector<std::size_t> sizes(sizes_initlist);
		sub_v = sub_vector_n<dim, T>(std::begin(v), sizes);
	}

	sub_vector_n<dim - 1, T> operator[](unsigned int i) {
		return sub_v[i];
	}
};

#endif
