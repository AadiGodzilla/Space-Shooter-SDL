#include "Timer.h"

Timer::Timer()
	: start(std::chrono::high_resolution_clock::now()), delta(0.0f)
{}

bool Timer::interval(double s)
{
	auto end = std::chrono::high_resolution_clock::now();
	delta = end - start;
	if (delta.count() >= s)
	{
		start = end;
		return true;
	}
	return false;
}