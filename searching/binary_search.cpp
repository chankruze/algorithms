/*
Author: chankruze (chankruze@gmail.com)
Created: Sun Mar 26 2023 23:20:31 GMT+0530 (India Standard Time)

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

void binarySearch(int arr[], int size, int key) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == key) {
      cout << key << " found at index: " << mid << endl;
      return;
    } else if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << key << " not found in the list" << endl;
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

  int key;

  cout << "Enter the element to search: ";
  cin >> key;

  binarySearch(arr, n, key);

  return 0;
}