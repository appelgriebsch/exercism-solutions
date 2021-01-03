#include "word_count.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// finds the index of a given word in the resultset
// returns -1 if word is not found in the resultset
static int find_word_index(const char* word, word_count_word_t* words) {

   int result = -1;

   for (int i = 0; i < MAX_WORDS; ++i) {
      if (strncmp(word, words[i].text, MAX_WORD_LENGTH) == 0) {
         result = i;
         break;
      }
   }

   return result;
}

int word_count(const char *input_text, word_count_word_t * words) {

   int words_found = 0;

   if ((!input_text) || !strlen(input_text)) {
      return words_found;
   }

   // iterate over all characters in the input string
   while (input_text && *input_text) {

      // find the start of a word
      char current_letter = *input_text;
      while (!isalnum(current_letter)) {
         current_letter = *(++input_text);
         // if we reach eof already, end the loop
         if (current_letter == '\0') {
            goto FIN;
         }
      }

      char current_word[MAX_WORD_LENGTH] = {0};
      int index_char = 0;

      // find the end of the current word
      // adding each letter found to the current word
      do {

         if (index_char >= MAX_WORD_LENGTH) {
            words_found = EXCESSIVE_LENGTH_WORD;
            goto FIN;
         }

         current_word[index_char++] = tolower(current_letter);
         current_letter = *(++input_text);

         // apostrophe in a word is ok
         if (current_letter == '\'' && isalnum(*(input_text + 1))) {
            continue;
         }
         else if ispunct(current_letter) {
            // any other kind of punctuations end the current word
            break;
         }

      } while (!iscntrl(current_letter) && !isspace(current_letter));

      int word_index = find_word_index(current_word, words);

      if (word_index == -1) {
         int index_word = words_found++;
         if (index_word >= MAX_WORDS) {
            words_found = EXCESSIVE_NUMBER_OF_WORDS;
            goto FIN;
         }
         strncpy(words[index_word].text, current_word, MAX_WORD_LENGTH);
         words[index_word].count = 1;
      }
      else {
         words[word_index].count++;
      }
   }

FIN:
   return words_found;
}
