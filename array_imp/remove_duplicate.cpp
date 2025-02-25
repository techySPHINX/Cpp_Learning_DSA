
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
 if (nums.empty()) return 0;

 int index = 1;
 for (int i = 1; i < nums.size(); ++i) {
  if (nums[i] != nums[i - 1]) {
   nums[index++] = nums[i];
  }
 }
 return index;
}

int main() {
 std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
 int newLength = removeDuplicates(nums);

 std::cout << "Array after removing duplicates: ";
 for (int i = 0; i < newLength; ++i) {
  std::cout << nums[i] << " ";
 }
 std::cout << std::endl;

 return 0;
}
 
