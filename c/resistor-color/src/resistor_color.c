#include "resistor_color.h"

int color_code(resistor_band_t color_band) {
  return color_band;
}

int* colors() {
  static int color_array[10];

  for (int i = 0; i < 10; ++i) {
    color_array[i] = i;
  }

  return color_array;
}
