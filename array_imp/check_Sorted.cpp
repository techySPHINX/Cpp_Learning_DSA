#include <iostream>
#include <vector>

bool isSortedAndRemoveDuplicates(std::vector<int>& arr) {
 if (arr.empty()) return true;

 bool isSorted = true;
 int writeIndex = 1;

 for (int i = 1; i < arr.size(); ++i) {
  if (arr[i] < arr[i - 1]) {
   isSorted = false;
  }
  if (arr[i] != arr[i - 1]) {
   arr[writeIndex++] = arr[i];
  }
 }

 arr.resize(writeIndex);
 return isSorted;
}

int main() {
 std::vector<int> arr = {1, 2, 2, 3, 4, 4, 5};

 bool sorted = isSortedAndRemoveDuplicates(arr);

 std::cout << "Array is " << (sorted ? "sorted" : "not sorted") << std::endl;
 std::cout << "Array after removing duplicates: ";
 for (int num : arr) {
  std::cout << num << " ";
 }
 std::cout << std::endl;

 return 0;
}
