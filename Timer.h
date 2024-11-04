#pragma once

#include <chrono>
#include <unordered_map>

class Timer
{
private:
	std::chrono::high_resolution_clock::time_point m_start, m_end;
	std::chrono::milliseconds m_delta;
public:
	Timer();
	bool interval(double s);
};
