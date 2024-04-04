#include "timer.h"

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

float Timer::result_ms() {
    return this->duration.count() * 1000.0f;
}
