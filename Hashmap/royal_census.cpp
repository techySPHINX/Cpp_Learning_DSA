#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string mostfrequentName(vector<string> &nums){
 unordered_map<string,int> nameCount;
 string mostCommon;
 int maxCount = 0;

 for(const string &nums : names){
  nameCount[name]++;
  if(nameCount[name] > maxCount){
   maxCount = nameCount[name];
   mostCommon = name;
  }
 }
 return mostCommon;
}
