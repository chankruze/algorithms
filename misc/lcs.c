/*
Author: chankruze (chankruze@gmail.com)
Created: Sun May 21 2023 23:22:30 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2023 and beyond
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to find the length of the LCS
int lcsLength(char* str1, char* str2, int len1, int len2) {
  int lcs[len1 + 1][len2 + 1];
  int i, j;

  // Building the LCS matrix
  for (i = 0; i <= len1; i++) {
    for (j = 0; j <= len2; j++) {
      if (i == 0 || j == 0)
        lcs[i][j] = 0;
      else if (str1[i - 1] == str2[j - 1])
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
      else
        lcs[i][j] = (lcs[i - 1][j] > lcs[i][j - 1]) ? lcs[i - 1][j] : lcs[i][j - 1];
    }
  }

  return lcs[len1][len2];
}

// Function to find and print the LCS
void printLcs(char* str1, char* str2, int len1, int len2) {
  int lcs_length = lcsLength(str1, str2, len1, len2);
  char lcs[lcs_length + 1];
  int index = lcs_length;
  int i = len1, j = len2;

  lcs[lcs_length] = '\0';  // Null-terminate the LCS string

  // Building the LCS string by traversing the LCS matrix
  while (i > 0 && j > 0) {
    if (str1[i - 1] == str2[j - 1]) {
      lcs[index - 1] = str1[i - 1];
      i--;
      j--;
      index--;
    } else if (lcsLength(str1, str2, i - 1, j) > lcsLength(str1, str2, i, j - 1))
      i--;
    else
      j--;
  }

  printf("The Longest Common Subsequence is: %s\n", lcs);
}

// Sample usage
int main() {
  char str1[MAX_LENGTH];
  char str2[MAX_LENGTH];

  printf("Enter the first string: ");
  fgets(str1, sizeof(str1), stdin);
  str1[strcspn(str1, "\n")] = '\0';  // Remove the trailing newline character

  printf("Enter the second string: ");
  fgets(str2, sizeof(str2), stdin);
  str2[strcspn(str2, "\n")] = '\0';  // Remove the trailing newline character

  int len1 = strlen(str1);
  int len2 = strlen(str2);

  printLcs(str1, str2, len1, len2);

  return 0;
}
