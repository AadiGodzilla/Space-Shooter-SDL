#pragma once

#include <chrono>

class Timer
{
	std::chrono::high_resolution_clock::time_point start;
	std::chrono::duration<double> delta;

public:
	Timer();
	bool interval(double s);
};
