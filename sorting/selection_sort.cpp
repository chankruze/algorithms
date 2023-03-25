/*
Author: chankruze (chankruze@gmail.com)
Created: Sat Mar 25 2023 19:13:32 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2023 and beyond
*/

#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr[] = {5, 1, 6, -1, 1};

  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Unsorted: ";
  printArray(arr, n);

  // main loop for each pass
  // n - 1 passes
  for (int i = 0; i < n - 1; i++) {
    // find min element in unsorted array
    int min = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    // check if min element is not already at first position
    if (min == i) {
      continue;
    }

    // swap min element with first element
    int temp = arr[min];
    arr[min] = arr[i];
    arr[i] = temp;

    // print array after each pass
    cout << "Pass " << i + 1 << ": ";
    printArray(arr, n);
  }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)