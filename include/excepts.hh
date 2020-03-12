#include <stdexcept>
#include <string>

#ifndef INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_HELPER_EXCEPTS_HH_
#define INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_HELPER_EXCEPTS_HH_

namespace de_uni_frankfurt_itp {
namespace reisinger {
namespace tools {

class help_required: public std::runtime_error {
public:
	help_required(std::string what) :
			runtime_error(what) {

	}
	help_required(const char* what) :
			runtime_error(what) {

	}
};

class syntax_required: public std::runtime_error {
public:
	syntax_required(std::string what) :
			runtime_error(what) {

	}
	syntax_required(const char* what) :
			runtime_error(what) {

	}
};

}
}
}

#endif
