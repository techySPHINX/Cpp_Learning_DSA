// A young explorer has a map with hidden locations.The Grand Master gives a second smaller map and asks : "Can you tell me if every location on this small map is already in the big map?"

#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool isSubset(set<int> &bigMap, set<int> &smallMap)
{
 for (int location : smallMap)
 {
  if (bigMap.find(location) == bigMap.end())
   return false;
 }
 return true;
}

int main()
{
 set<int> bigMap = {1, 2, 3, 4, 5, 6, 7, 8};
 set<int> smallMap = {2, 4, 6};

 if (isSubset(bigMap, smallMap))
 {
  cout << "The smaller map is a valid subset!" << endl;
 }
 else
 {
  cout << "The smaller map has locations not in the big map!" << endl;
 }

 return 0;
}
