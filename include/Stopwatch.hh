#include <chrono>
#include <string>

#ifndef INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_STOPWATCH_HH_
#define INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_STOPWATCH_HH_

namespace de_uni_frankfurt_itp {
namespace reisinger {
namespace tools {

class Stopwatch {
public:
	Stopwatch();

	void pause();
	void resume();

	std::chrono::milliseconds reset();
	std::chrono::milliseconds check() const;

private:
	std::chrono::steady_clock::time_point m_start_time;
	std::chrono::steady_clock::duration m_duration { 0 };
	bool paused;

};

}
}
}

#endif
