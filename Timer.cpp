#include "Timer.h"

Timer::Timer() :
	m_start(std::chrono::high_resolution_clock::now()), m_delta(0)
{

}

bool Timer::interval(double ms)
{
	if (this != nullptr)
	{
		m_end = std::chrono::high_resolution_clock::now();
		m_delta = std::chrono::duration_cast<std::chrono::milliseconds>(m_end - m_start);
		if (m_delta.count() >= ms)
		{
			m_start = m_end;
			return true;
		}
		return false;
	}
}
