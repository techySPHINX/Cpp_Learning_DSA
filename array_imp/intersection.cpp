#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) {
 std::unordered_set<int> set1(nums1.begin(), nums1.end());
 std::unordered_set<int> resultSet;
 
 for (int num : nums2) {
  if (set1.find(num) != set1.end()) {
   resultSet.insert(num);
  }
 }
 
 return std::vector<int>(resultSet.begin(), resultSet.end());
}

int main() {
 std::vector<int> nums1 = {1, 2, 2, 1};
 std::vector<int> nums2 = {2, 2};
 
 std::vector<int> result = intersection(nums1, nums2);
 
 std::cout << "Intersection of the two arrays: ";
 for (int num : result) {
  std::cout << num << " ";
 }
 std::cout << std::endl;
 
 return 0;
}
