#pragma once
class Timer
{
};

class Stopwatch
{
public:
	Stopwatch();
	void Start();

	const float GetElapsedTimeSec(); //초 단위
	const float GetElapsedTimeMS(); //밀리 초 단위

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};
