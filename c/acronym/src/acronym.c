#include "acronym.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *abbreviate(const char *phrase) {

  // if phrase is not set
  // return early
  if ((!phrase) || !strlen(phrase)){
    return NULL;
  }

  // make room for resulting characters
  int index = 0;
  char* result = calloc(40, sizeof(char));

  // iterate over words in input string
  const char* current_token = phrase;
  while (current_token) {
    char first_letter = '\0';

    do {
      first_letter = *current_token;
      current_token++;
    } while (!isalpha(first_letter));

    result[index++] = toupper(first_letter);
    current_token = strpbrk(current_token, " -");
  }

  return result;
}
