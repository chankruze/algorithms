/*
Author: chankruze (chankruze@gmail.com)
Created: Sat Mar 25 2023 19:33:55 GMT+0530 (India Standard Time)

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

void swap(int arr[], int x, int y) {
  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}

int partition(int arr[], int low, int high) {
  // select the first element as pivot
  int pivot = arr[low];
  // i is the index of the first element greater than pivot
  int i = low;
  // j is the index of the last element greater than pivot
  int j = high;
  // repeat until i and j cross each other
  while (i < j) {
    // increment i until you find an element greater than pivot
    while (arr[i] <= pivot) i++;
    // decrement j until you find an element less than pivot
    while (arr[j] > pivot) j--;
    // if i and j have not crossed each other
    if (i < j) swap(arr, i, j);
  }
  // swap the pivot with the jth element
  swap(arr, low, j);
  // return the index of the pivot
  return j;
}

void quickSort(int arr[], int low, int high) {
  // if there are more than one elements
  if (low < high) {
    // partition the array
    int pivot = partition(arr, low, high);
    // sort the left sub-array
    quickSort(arr, low, pivot - 1);
    // sort the right sub-array
    quickSort(arr, pivot + 1, high);
  }
}

int main() {
  int arr[] = {5, 4, 3, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  // print the array before sorting
  cout << "Unsorted: ";
  printArray(arr, n);
  // sort the array
  quickSort(arr, 0, n - 1);
  // print the array after sorting
  cout << "Sorted: ";
  printArray(arr, n);

  return 0;
}

// Time Complexity: Best Case: O(nlogn)
//                  Average Case: O(nlogn)
//                  Worst Case: O(n^2)
// Space Complexity: O(n)

// To improve the worst case time complexity, we can:
// 1. Randomly select a pivot
// 2. Use median of three as pivot
// 3. Use insertion sort for small sub-arrays
