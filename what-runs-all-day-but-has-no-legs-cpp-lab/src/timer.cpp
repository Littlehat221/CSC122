#include <string>
#include "timer.hpp"

Timer::Timer() {
    running = false;
    hasStarted = false;
    elapsedSeconds = 0;
}

void Timer::start() {
    if (running) {
        startTime = std::chrono::steady_clock::now();
        elapsedSeconds = 0;
    } else {
        startTime = std::chrono::steady_clock::now();
        running = true;
        hasStarted = true;
    }
}

void Timer::stop() {
    if (!running) {
        return;
    }

    endTime = std::chrono::steady_clock::now();
    //truncate time
    elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
    running = false;
}

long Timer::elapsed() const {
    if (!hasStarted) {
        return 0;
    }

    if (running) {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
    }

    return elapsedSeconds;
}

//add one one
void Timer::pretty_print() const {
    long total = elapsed();

    if (total == 0) {
        std::cout << "No time has passed." << std::endl;
        return;
    }

    int hours = total / 3600;
    int minutes = (total % 3600) / 60;
    int seconds = total % 60;

    bool first = true;

    if (hours > 0) {
        std::cout << hours << (hours == 1 ? " hour" : " hours");
        first = false;
    }

    if (minutes > 0) {
        if (!first) std::cout << ", ";
        std::cout << minutes << (minutes == 1 ? " minute" : " minutes");
        first = false;
    }

    if (seconds > 0) {
        if (!first) std::cout << ", ";
        std::cout << seconds << (seconds == 1 ? " second" : " seconds");
    }

    std::cout << " have passed." << std::endl;
}

//add on two
Timer Timer::add(Timer addtee) const {
    Timer result;
    result.elapsedSeconds = this->elapsed() + addtee.elapsed();
    result.hasStarted = true;
    result.running = false;
    return result;
}

Timer Timer::subtract(Timer subtractee) const {
    Timer result;
    long diff = this->elapsed() - subtractee.elapsed();
    result.elapsedSeconds = (diff < 0) ? 0 : diff; // prevent negative time
    result.hasStarted = true;
    result.running = false;
    return result;
}