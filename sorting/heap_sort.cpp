/*
Author: chankruze (chankruze@gmail.com)
Created: Sun May 21 2023 19:32:15 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2023 and beyond
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

// Function to heapify a subtree rooted at index 'rootIndex' in arr[]
void heapify(vector<int>& arr, int n, int rootIndex) {
  int largest = rootIndex;  // Initialize largest as root
  int leftChild = 2 * rootIndex + 1;
  int rightChild = 2 * rootIndex + 2;

  // If left child is larger than root
  if (leftChild < n && arr[leftChild] > arr[largest])
    largest = leftChild;

  // If right child is larger than the largest so far
  if (rightChild < n && arr[rightChild] > arr[largest])
    largest = rightChild;

  // If the largest element is not the root
  if (largest != rootIndex) {
    swap(arr[rootIndex], arr[largest]);

    // Recursively heapify the affected sub-tree
    heapify(arr, n, largest);
  }
}

// The main function to perform heap sort
void heapSort(vector<int>& arr) {
  int n = arr.size();

  // Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  // One by one extract an element from the heap
  for (int i = n - 1; i > 0; i--) {
    // Move the current root (maximum element) to the end
    swap(arr[0], arr[i]);

    // call max heapify on the reduced heap
    heapify(arr, i, 0);
  }
}

// Function to print an array
void printArray(const vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Test the code
int main() {
  vector<int> arr = {12, 11, 13, 5, 6, 7};

  cout << "Original array:" << endl;
  printArray(arr);

  heapSort(arr);

  cout << "Sorted array:" << endl;
  printArray(arr);

  return 0;
}
