/*
Author: chankruze (chankruze@gmail.com)
Created: Sun May 21 2023 20:17:26 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2023 and beyond
*/

#include <stdio.h>

// Structure to represent an item
struct Item {
  int weight;
  int value;
};

// Function to calculate the maximum of two integers
int max(int a, int b) {
  return (a > b) ? a : b;
}

// Function to solve the knapsack problem
int knapsack(int capacity, struct Item items[], int num_items) {
  int i, w;
  int dp[num_items + 1][capacity + 1];

  // Build the table dp[][] in bottom-up manner
  for (i = 0; i <= num_items; i++) {
    for (w = 0; w <= capacity; w++) {
      if (i == 0 || w == 0)
        dp[i][w] = 0;
      else if (items[i - 1].weight <= w)
        dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
      else
        dp[i][w] = dp[i - 1][w];
    }
  }

  // Return the maximum value
  return dp[num_items][capacity];
}

int main() {
  int num_items, capacity;
  printf("Enter the number of items: ");
  scanf("%d", &num_items);

  struct Item items[num_items];

  // Read item weights and values from the user
  for (int i = 0; i < num_items; i++) {
    printf("Enter weight and value for item %d: ", i + 1);
    scanf("%d %d", &items[i].weight, &items[i].value);
  }

  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  int max_value = knapsack(capacity, items, num_items);

  printf("The maximum value that can be achieved is: %d\n", max_value);

  return 0;
}
