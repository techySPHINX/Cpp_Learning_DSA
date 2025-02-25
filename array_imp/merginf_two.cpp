#include <iostream>
#include <vector>

void mergeArrays(const std::vector<int>& arr1, const std::vector<int>& arr2, std::vector<int>& mergedArray) {
 int i = 0, j = 0, k = 0;
 int n1 = arr1.size();
 int n2 = arr2.size();
 
 while (i < n1 && j < n2) {
  if (arr1[i] <= arr2[j]) {
   mergedArray[k++] = arr1[i++];
  } else {
   mergedArray[k++] = arr2[j++];
  }
 }
 
 while (i < n1) {
  mergedArray[k++] = arr1[i++];
 }
 
 while (j < n2) {
  mergedArray[k++] = arr2[j++];
 }
}


std::vector<int> mergeArraysOptimal(const std::vector<int>& arr1, const std::vector<int>& arr2) {
 std::vector<int> mergedArray;
 mergedArray.reserve(arr1.size() + arr2.size());
 
 auto it1 = arr1.begin();
 auto it2 = arr2.begin();
 
 while (it1 != arr1.end() && it2 != arr2.end()) {
  if (*it1 <= *it2) {
   mergedArray.push_back(*it1++);
  } else {
   mergedArray.push_back(*it2++);
  }
 }
 
 while (it1 != arr1.end()) {
  mergedArray.push_back(*it1++);
 }
 
 while (it2 != arr2.end()) {
  mergedArray.push_back(*it2++);
 }
 
 return mergedArray;
}

int main() {
 std::vector<int> arr1 = {1, 3, 5, 7};
 std::vector<int> arr2 = {2, 4, 6, 8};
 std::vector<int> mergedArray(arr1.size() + arr2.size());
 
 mergeArrays(arr1, arr2, mergedArray);
 
 std::cout << "Merged array: ";
 for (int i = 0; i < mergedArray.size(); i++) {
  std::cout << mergedArray[i] << " ";
 }
 std::cout << std::endl;
 
 return 0;
}
