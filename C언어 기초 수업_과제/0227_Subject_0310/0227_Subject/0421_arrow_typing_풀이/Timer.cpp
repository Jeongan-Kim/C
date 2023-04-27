#include "stdafx.h"
#include "Timer.h"

Stopwatch::Stopwatch()
{
	Start();
}

void Stopwatch::Start()
{
	start_time = std::chrono::high_resolution_clock::now();
}

const float Stopwatch::GetElapsedTimeSec()
{
	std::chrono::duration<double, std::milli> ms = std::chrono::high_resolution_clock::now() - start_time;
	return static_cast<float>(ms.count() / 1000.0);
}

const float Stopwatch::GetElapsedTimeMS()
{
	std::chrono::duration<double, std::milli> ms = std::chrono::high_resolution_clock::now() - start_time;
	return static_cast<float>(ms.count());
}
