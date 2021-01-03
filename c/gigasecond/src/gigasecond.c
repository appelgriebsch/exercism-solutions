#include "gigasecond.h"
#include <math.h>

time_t gigasecond_after(time_t start) {
  return start + pow(10, 9);
}
