#include <iostream>
#include <vector>
#include<set>

using namespace std;

void removeDuplicatesOrdered(vector<int> &nums){
 set<int> uniqueNums(nums.begin(), nums.end());
 nums.assign(uniqueNums.begin(), uniqueNums.end());
}

void removeDuplicatesUnordered(vector<int> &nums){
 unordered_set<int> seen;
 vector<int> uniqueSums;

 for(int num: nums){
  if(seen.find(num) == seen.end()){
   seen.insert(num);
   uniqueNums.push_back(num);
  }
 }

 nums = uniqueNums;
}


