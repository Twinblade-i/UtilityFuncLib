#ifndef _TIMER_H_
#define _TIMER_H_

#include <chrono>

class Timer {
   private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;
    std::chrono::duration<float> duration;
    bool start_mark, pause_mark;

   public:
    Timer();
    ~Timer();

    void start();
    void end();
    void pause();
    void proceed();
    float result_ms();
};

#endif