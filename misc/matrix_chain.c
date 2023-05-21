/*
Author: chankruze (chankruze@gmail.com)
Created: Sun May 21 2023 23:24:49 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2023 and beyond
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void printParenthesis(int i, int j, int n, int *bracket, char *name) {
  if (i == j) {
    printf("%c", name[i]);
    return;
  }

  printf("(");

  printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);

  printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);
  printf(")");
}

void matrixChainOrder(int p[], int n) {
  int m[n][n];
  int bracket[n][n];

  for (int i = 1; i < n; i++)
    m[i][i] = 0;

  for (int L = 2; L < n; L++) {
    for (int i = 1; i < n - L + 1; i++) {
      int j = i + L - 1;
      m[i][j] = INT_MAX;

      for (int k = i; k <= j - 1; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j]) {
          m[i][j] = q;
          bracket[i][j] = k;
        }
      }
    }
  }

  char *name = (char *)malloc(sizeof(char) * n);
  for (int i = 0; i < n; i++)
    name[i] = 'A' + i;

  printf("Optimal Parenthesization is: ");
  printParenthesis(1, n - 1, n, (int *)bracket, name);
  printf("\nOptimal Cost is: %d\n", m[1][n - 1]);

  free(name);
}

int main() {
  int n;
  printf("Enter the number of matrices: ");
  scanf("%d", &n);

  int *arr = (int *)malloc(sizeof(int) * n);
  printf("Enter the dimensions of the matrices:\n");
  for (int i = 0; i < n; i++) {
    printf("Dimension of Matrix %d: ", i + 1);
    scanf("%d", &arr[i]);
  }

  matrixChainOrder(arr, n);

  free(arr);

  return 0;
}
