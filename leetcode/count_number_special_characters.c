#include <stdio.h>
#include <string.h>

int numberOfSpecialChars(char *word) {
  // Fixed size arrays for 26 letters of the alphabet
  int lower_exists[26] = {0};
  int upper_exists[26] = {0};
  int special_count = 0;

  // Step 1: Scan the string and record seen characters
  for (int i = 0; word[i] != '\0'; i++) {
    if (word[i] >= 'a' && word[i] <= 'z') {
      lower_exists[word[i] - 'a'] = 1; // Map 'a'->0, 'b'->1, etc.
    } else if (word[i] >= 'A' && word[i] <= 'Z') {
      upper_exists[word[i] - 'A'] = 1; // Map 'A'->0, 'B'->1, etc.
    }
  }

  // Step 2: Count how many letters exist in both cases
  for (int i = 0; i < 26; i++) {
    if (lower_exists[i] && upper_exists[i]) {
      special_count++;
    }
  }

  return special_count;
}

int main() {
  // Test Example 1
  char word1[] = "aaAbcBC";
  printf("Output: %d (Expected: 3)\n", numberOfSpecialChars(word1));

  // Test Example 2
  char word2[] = "abc";
  printf("Output: %d (Expected: 0)\n", numberOfSpecialChars(word2));

  // Test Example 3
  char word3[] = "abBCab";
  printf("Output: %d (Expected: 1)\n", numberOfSpecialChars(word3));

  char word4[] = "aAbBCcDdaaaaaaZzQqWw";
  printf("Output: %d (Expected: 3)\n", numberOfSpecialChars(word4));
  return 0;
}
