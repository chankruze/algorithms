/*
Author: chankruze (chankruze@gmail.com)
Created: Sun May 21 2023 20:58:30 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2023 and beyond
*/

#include <stdio.h>

typedef struct {
  double weight;
  double value;
  double ratio;
} Item;

void swap(Item* a, Item* b) {
  Item temp = *a;
  *a = *b;
  *b = temp;
}

void sortItemsByRatio(Item* items, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (items[j].ratio < items[j + 1].ratio) {
        swap(&items[j], &items[j + 1]);
      }
    }
  }
}

double fractionalKnapsack(int capacity, Item* items, int n) {
  sortItemsByRatio(items, n);

  int currentWeight = 0;
  double totalValue = 0.0;

  for (int i = 0; i < n; i++) {
    if (currentWeight + items[i].weight <= capacity) {
      currentWeight += items[i].weight;
      totalValue += items[i].value;
    } else {
      int remainingWeight = capacity - currentWeight;
      totalValue += (items[i].value / items[i].weight) * remainingWeight;
      break;
    }
  }

  return totalValue;
}

int main() {
  int n;
  printf("Enter the number of items: ");
  scanf("%d", &n);

  Item items[n];
  for (int i = 0; i < n; i++) {
    printf("Enter the weight and value of item %d: ", i + 1);
    scanf("%lf %lf", &items[i].weight, &items[i].value);
    items[i].ratio = items[i].value / items[i].weight;
  }

  int capacity;
  printf("Enter the knapsack capacity: ");
  scanf("%d", &capacity);

  double maxValue = fractionalKnapsack(capacity, items, n);

  printf("The maximum value that can be obtained is: %.2lf\n", maxValue);

  return 0;
}
