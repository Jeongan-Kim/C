#pragma once
class Timer
{
};

class Stopwatch
{
public:
	Stopwatch();
	void Start();

	const float GetElapsedTimeSec(); //�� ����
	const float GetElapsedTimeMS(); //�и� �� ����

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};
