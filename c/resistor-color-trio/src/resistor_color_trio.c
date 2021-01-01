#include "resistor_color_trio.h"
#include <math.h>

const char* OHMS = "ohms";
const char* KILOOHMS = "kiloohms";

resistor_value_t color_code(const resistor_band_t color_band[static 3]) {
  resistor_value_t result = {
    .value = (color_band[0] * 10 + color_band[1]) * pow(10, color_band[2]),
    .unit = OHMS
  };

  if ((result.value % 1000) == 0) {
    result.value = result.value / 1000;
    result.unit = KILOOHMS;
  }

  return result;
}
