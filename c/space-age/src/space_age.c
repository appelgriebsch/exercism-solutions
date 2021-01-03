#include "space_age.h"

static const float EARTH_YEAR[] = {
   0.2408467,  // MERCURY
   0.61519726, // VENUS
   1.0,        // EARTH
   1.8808158,  // MARS
   11.862615,  // JUPITER
   29.447498,  // SATURN
   84.016846,  // URANUS
   164.79132   // NEPTUNE
};

static const float SECONDS_PER_YEAR = 31557600.0;

float convert_planet_age(planet_t planet, int64_t input) {

   return (input / SECONDS_PER_YEAR) / EARTH_YEAR[planet];
}
