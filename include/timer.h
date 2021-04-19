#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <set>
#include <utility>

struct Timer {
  std::chrono::_V2::system_clock::time_point start, end;

  void Play() {
    isStop_ = false;
    start = std::chrono::high_resolution_clock::now();
  }

  float Stop() {
    if (!isStop_) {
      end = std::chrono::high_resolution_clock::now();
      duration = end - start;
      isStop_ = true;
    }
    return duration.count();
  }

  float Get() const {
    return duration.count();
  }

 private:
  bool isStop_ = false;
  std::chrono::duration<float> duration;
};

#endif