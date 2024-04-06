#include "timer.h"

#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>

Timer::Timer() {
    this->start_mark = false;
    this->pause_mark = false;
}

Timer::~Timer() {
    this->duration = std::chrono::duration<float>::zero();

    this->start_mark = false;
    this->pause_mark = false;
}

void Timer::start() {
    this->start_point = std::chrono::high_resolution_clock::now();
    this->start_mark = true;
}

void Timer::end() {
    if (!this->start_mark) {
        throw std::logic_error("havn't start.");
    }
    if (!this->pause_mark) {
        this->end_point = std::chrono::high_resolution_clock::now();
        this->duration += this->end_point - this->start_point;
    }
}

void Timer::pause() {
    if (!this->start_mark) {
        throw std::logic_error("havn't start.");
    }
    if (this->pause_mark) {
        throw std::logic_error("already pause.");
    }

    this->end_point = std::chrono::high_resolution_clock::now();
    this->duration += this->end_point - this->start_point;
    this->pause_mark = true;
}

void Timer::proceed() {
    if (!this->pause_mark) {
        throw std::logic_error("no pause mark.");
    }

    this->start_point = std::chrono::high_resolution_clock::now();
    this->pause_mark = false;
}

void Timer::print_current_time() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    std::time_t seconds = std::chrono::system_clock::to_time_t(now);
    std::tm* timeinfo = std::localtime(&seconds);

    std::cout << "Current date and time: " << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S.")
              << std::setfill('0') << std::setw(3) << millis.count() % 1000 << "\n";
}

float Timer::result_ms() {
    return this->duration.count() * 1000.0f;
}
