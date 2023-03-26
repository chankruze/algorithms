/*
Author: chankruze (chankruze@gmail.com)
Created: Sun Mar 26 2023 00:58:57 GMT+0530 (India Standard Time)

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

void merge(int arr[], int left, int mid, int right) {
  // calculate the size of the array
  int size = right - left + 1;
  // create a temp array
  int temp_arr[size];

  // left index of the left half (i pointer starts from left)
  int i = left;
  // left index of the right half (j pointer starts from mid + 1)
  int j = mid + 1;
  // index of the temp array (k pointer starts from left)
  int k = left;

  // iterate over both halves and add the smaller element to the temp array
  // until one of the halves is exhausted
  while (i <= mid && j <= right) {
    if (arr[i] < arr[j]) {
      temp_arr[k++] = arr[i++];
    } else {
      temp_arr[k++] = arr[j++];
    }
  }

  // if the left half is exhausted, add the remaining elements of the right half to the temp array
  // if the right half is exhausted, add the remaining elements of the left half to the temp array
  if (i > mid) {
    while (j <= right) {
      temp_arr[k++] = arr[j++];
    }
  } else {
    while (i <= mid) {
      temp_arr[k++] = arr[i++];
    }
  }

  // copy the temp array to the original array
  for (int i = left; i <= right; i++) {
    arr[i] = temp_arr[i];
  }
}

void mergeSort(int arr[], int left, int right) {
  // if left < right, then there are more than 1 elements
  if (left < right) {
    int mid = (left + right) / 2;
    // sort left half
    mergeSort(arr, left, mid);
    // sort right half
    mergeSort(arr, mid + 1, right);
    // merge both halves
    merge(arr, left, mid, right);
  }
}

int main() {
  int n;
  cout << "Enter size of array: ";
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cout << "Enter element " << i << ": ";
    cin >> arr[i];
  }

  cout << "Unsorted: ";
  printArray(arr, n);

  mergeSort(arr, 0, n - 1);

  cout << "Sorted: ";
  printArray(arr, n);
}