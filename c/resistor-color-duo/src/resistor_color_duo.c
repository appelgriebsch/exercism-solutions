#include "resistor_color_duo.h"

int color_code(const resistor_band_t color_band[static 2]) {
  return color_band[0] * 10 + color_band[1];
}
