#pragma once
class Timer
{
public:
    Timer();
    ~Timer() = default;

    bool Initialize();
    void Update();

    const float GetDeltaTimeMs() { return static_cast<float>(delta_time_ms); }
    const float GetDeltaTimeSEC() { return static_cast<float>(delta_time_ms / 1000.0); }
    

private:
    double delta_time_ms = 0.0;
    std::chrono::time_point<std::chrono::high_resolution_clock> previous_time;
};

class Stopwatch
{
public:
    Stopwatch();

    void Start();

    const float GetElapsedTimeSec();
    const float GetElapsedTimeMs();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};

