/*
Author: chankruze (chankruze@gmail.com)
Created: Sat Mar 25 2023 18:43:32 GMT+0530 (India Standard Time)

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

  // main loop for each pass
  // n - 1 passes but we start from 1
  for (int i = 1; i < n; i++) {
    // store current element
    int temp = arr[i];
    // store previous element index (inner loop starts from i - 1)
    int j = i - 1;

    // move elements of arr[0..i-1], that are greater than temp,
    // to one position ahead of their current position
    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j--;
    }

    // insert temp at correct position
    arr[j + 1] = temp;

    // print array after each pass
    cout << "Pass " << i << ": ";
    printArray(arr, n);
  }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
