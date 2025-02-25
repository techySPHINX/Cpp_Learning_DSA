#include <iostream>
#include <vector>
#include <limits.h>

void findLargestAndSecondLargest(const std::vector<int>& arr, int& largest, int& secondLargest) {
 largest = INT_MIN;
 secondLargest = INT_MIN;

 for (int num : arr) {
  if (num > largest) {
   secondLargest = largest;
   largest = num;
  } else if (num > secondLargest && num != largest) {
   secondLargest = num;
  }
 }
}

void findSmallestAndSecondSmallest(const std::vector<int>& arr, int& smallest, int& secondSmallest) {
 smallest = INT_MAX;
 secondSmallest = INT_MAX;

 for (int num : arr) {
  if (num < smallest) {
   secondSmallest = smallest;
   smallest = num;
  } else if (num < secondSmallest && num != smallest) {
   secondSmallest = num;
  }
 }
}

int main() {
 std::vector<int> arr = {10, 20, 4, 45, 99, 99, 23};
 int largest = INT_MIN, secondLargest = INT_MIN;

 findLargestAndSecondLargest(arr, largest, secondLargest);

 std::cout << "Largest element: " << largest << std::endl;
 std::cout << "Second largest element: " << secondLargest << std::endl;

 return 0;
}


