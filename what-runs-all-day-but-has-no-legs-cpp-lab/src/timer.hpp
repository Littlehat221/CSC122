#include <string>
#include <chrono>
#include <iostream>

class Timer {
private:
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::time_point<std::chrono::steady_clock> endTime;

    bool running;
    bool hasStarted;
    long elapsedSeconds; // stored elapsed time

public:
    Timer();

    void start();
    void stop();
    long elapsed() const;

    // Add-ons
    void pretty_print() const;

    Timer add(Timer addtee) const;
    Timer subtract(Timer subtractee) const;
};
