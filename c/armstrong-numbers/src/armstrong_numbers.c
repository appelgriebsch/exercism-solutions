#include "armstrong_numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool is_armstrong_number(int candidate) {
  char buffer[8];
  int length = snprintf(buffer, 8, "%d", candidate);

  int result = 0;
  for (int i = 0; i < length; ++i) {
    int digit = buffer[i] - '0';
    result += pow(digit, length);
  }

  return result == candidate;
}
