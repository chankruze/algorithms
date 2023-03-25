/*
Author: chankruze (chankruze@gmail.com)
Created: Sun Mar 26 2023 00:29:26 GMT+0530 (India Standard Time)

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
  int arr[] = {5, 4, 3, 2, 1};

  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Unsorted: ";
  printArray(arr, n);

  // bubble sort algorithm
  // main loop for each pass (n - 1 passes)
  for (int i = 0; i < n; i++) {
    // inner loop for each pass
    for (int j = 0; j < n - i - 1; j++) {
      // swap if current element is greater than next element
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }

    // print array after each pass
    cout << "Pass " << i + 1 << ": ";
    printArray(arr, n);
  }
  cout << "Sorted: ";
  printArray(arr, n);

  return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)