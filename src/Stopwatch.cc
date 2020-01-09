#include <sstream>
#include <iomanip>
#include <queue>

#include <Stopwatch.hh>

namespace de_uni_frankfurt_itp {
namespace reisinger {
namespace tools {

Stopwatch::Stopwatch() :
		paused(false) {
	m_start_time = std::chrono::steady_clock::now();
}

void Stopwatch::pause() {
	if (!paused)
		m_duration += std::chrono::steady_clock::now() - m_start_time;
	paused = true;
}

void Stopwatch::resume() {
	if (paused)
		m_start_time = std::chrono::steady_clock::now();
	paused = false;
}

std::chrono::milliseconds Stopwatch::reset() {
	const auto duration = check();
	m_duration = std::chrono::steady_clock::duration { 0 };
	m_start_time = std::chrono::steady_clock::now();
	return duration;
}

std::chrono::milliseconds Stopwatch::check() const {
	const auto duration = (std::chrono::steady_clock::now() - m_start_time) + m_duration;
	return std::chrono::duration_cast<std::chrono::milliseconds>(duration);
}

}
}
}
