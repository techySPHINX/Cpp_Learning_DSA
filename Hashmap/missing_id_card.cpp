#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int firstUniqueId(vector<int> ids)
{
 unordered_map<int, int> idCount;

 for (int id : ids)
 {
  idCount[id++];
 }

 for (int id : ids)
 {
  if (idCount[id] == 1)
  {
   return id;
  }
 }

 return -1;
}
