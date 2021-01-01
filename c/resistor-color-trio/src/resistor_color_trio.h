#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

typedef enum {

  BLACK = 0,
  BROWN,
  RED,
  ORANGE,
  YELLOW,
  GREEN,
  BLUE,
  VIOLET,
  GREY,
  WHITE

} resistor_band_t;

extern const char* OHMS;
extern const char* KILOOHMS;

typedef struct resistor_value_t {

  int value;
  const char* unit;

} resistor_value_t;

resistor_value_t color_code(const resistor_band_t color_band[static 3]);

#endif
