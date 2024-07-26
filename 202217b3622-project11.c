#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
  // Iterate through the array elements
  for (int i = 0; i < n; i++) {
    // Check if current element matches the target
    if (arr[i] == target) {
      // Element found, return its index
      return i;
    }
  }
  // If loop completes without finding the target, return -1
  return -1;
}

int main() {
  int arr[] = {10, 2, 8, 5, 17};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 8;

  int result = linearSearch(arr, n, target);

  if (result == -1) {
    printf("Element not found in the array.\n");
  } else {
    printf("Element found at index: %d\n", result);
  }

  return 0;
}
