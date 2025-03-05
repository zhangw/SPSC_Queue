#include <sched.h>

bool cpupin(int cpuid) {
  cpu_set_t my_set;
  CPU_ZERO(&my_set);
  CPU_SET(cpuid, &my_set);
  if (sched_setaffinity(0, sizeof(cpu_set_t), &my_set)) {
    std::cout << "sched_setaffinity error: " << strerror(errno) << std::endl;
    return false;
  }
  std::cout << "sched_setaffinity to cpu id: " << cpuid << std::endl;

  return true;
}
