#ifndef _CHRONO_
#define _CHRONO_

#include <chrono>

namespace CXXChrono {
using Clock = std::chrono::steady_clock;
using TimePoint = Clock::time_point;

inline TimePoint now()
{
  return Clock::now();
}

inline std::int64_t diff_tps(TimePoint tp1, TimePoint tp2)
{
  return std::chrono::duration_cast<std::chrono::nanoseconds>(tp2 - tp1).count();
}

}

#endif // !_CHRONO_

