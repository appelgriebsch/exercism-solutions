#include "isogram.h"
#include <string.h>
#include <ctype.h>

bool is_isogram(const char phrase[]) {

  // check for NULL value and return early
  if (!phrase) {
    return false;
  }

  bool result = true;
  unsigned char char_count[26] = {0};

  // iterate over chars in phrase, get the lower char value,
  // map it to the distance from 'a' in alphabet
  // and increase the value for that char in the char_count array
  for (size_t i = 0; i < strlen(phrase); ++i) {
    unsigned char c = tolower(phrase[i]);

    // ignore those special chars from counting
    if ((c == '-') || (c == ' ')) {
      continue;
    }

    char_count[c - 'a'] += 1;
  }

  // check if there is at least one entry
  // in the char_count array with a value
  // larger than 1
  for (int i = 0; i < 26; ++i) {
    if (char_count[i] > 1) {
      result = false;
      break;
    }
  }

  return result;
}
