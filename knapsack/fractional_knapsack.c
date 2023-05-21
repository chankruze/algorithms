/*
Author: chankruze (chankruze@gmail.com)
Created: Sun May 21 2023 20:28:44 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2023 and beyond
*/

#include <stdio.h>

// Structure to represent an item
struct Item {
  int weight;
  int value;
  float valuePerWeight;
};

// Function to compare items based on value per weight ratio
int compareItems(const void* a, const void* b) {
  struct Item* item1 = (struct Item*)a;
  struct Item* item2 = (struct Item*)b;
  return item2->valuePerWeight - item1->valuePerWeight;
}

// Function to solve the fractional knapsack problem
float fractionalKnapsack(int capacity, struct Item items[], int num_items) {
  // Sort items based on value per weight ratio in non-increasing order
  qsort(items, num_items, sizeof(struct Item), compareItems);

  float totalValue = 0.0;
  int currentWeight = 0;

  // Iterate through all items and add them to the knapsack until capacity is reached
  for (int i = 0; i < num_items; i++) {
    // If adding the entire item is possible, add it and update capacity and total value
    if (currentWeight + items[i].weight <= capacity) {
      currentWeight += items[i].weight;
      totalValue += items[i].value;
    }
    // Otherwise, add a fraction of the item to fill the remaining capacity
    else {
      int remainingWeight = capacity - currentWeight;
      float fraction = (float)remainingWeight / items[i].weight;
      totalValue += items[i].value * fraction;
      break;
    }
  }

  // Return the maximum value
  return totalValue;
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
    items[i].valuePerWeight = (float)items[i].value / items[i].weight;
  }

  printf("Enter the capacity of the knapsack: ");
  scanf("%d", &capacity);

  float max_value = fractionalKnapsack(capacity, items, num_items);

  printf("The maximum value that can be achieved is: %.2f\n", max_value);

  return 0;
}
