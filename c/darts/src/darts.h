#ifndef DARTS_H
#define DARTS_H

typedef unsigned char uint8_t;

typedef struct coordinate_t {
  float x;
  float y;
} coordinate_t;

uint8_t score(coordinate_t coords);

#endif
