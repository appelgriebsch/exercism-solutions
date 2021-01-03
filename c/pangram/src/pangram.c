#include "pangram.h"
#include <string.h>
#include <ctype.h>

bool is_pangram(const char *sentence) {

  // check for NULL value and return early
  if (!sentence) {
    return false;
  }

  bool result = true;
  unsigned char chars[26] = {0};

  // iterate over chars in phrase, get the lower char value,
  // map it to the distance from 'a' in alphabet
  // and increase the value for that char in the char_count array
  for (size_t i = 0; i < strlen(sentence); ++i) {
    unsigned char c = tolower(sentence[i]);

    // ignore any chars not being from the alphabet
    if (!isalpha(c)) {
      continue;
    }

    chars[c - 'a'] += 1;
  }

  // check if there is any entry
  // in the char array with a value of zero
  for (int i = 0; i < 26; ++i) {
    if (chars[i] == 0) {
      result = false;
      break;
    }
  }

  return result;
}
