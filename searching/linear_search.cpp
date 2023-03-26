/*
Author: chankruze (chankruze@gmail.com)
Created: Sun Mar 26 2023 23:13:49 GMT+0530 (India Standard Time)

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

void linearSearch(int arr[], int size, int key) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key) {
      cout << key << " found at index: " << i << endl;
      return;
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

  linearSearch(arr, n, key);

  return 0;
}