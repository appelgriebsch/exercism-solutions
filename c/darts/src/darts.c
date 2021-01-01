#include "darts.h"
#include <math.h>

uint8_t score(coordinate_t coords) {
  float pos = sqrt(pow(coords.x, 2) + pow(coords.y, 2));

  if (pos > 10.0) {
    return 0;
  }
  else if (pos > 5.0) {
    return 1;
  }
  else if (pos > 1.0) {
    return 5;
  }

  return 10;
}
