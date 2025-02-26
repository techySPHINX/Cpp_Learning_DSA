#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> findCommonTreasures(set<int> &map1, set<int> &map2)
{
 set<int> commonTreasures;
 for (int treasure : map1)
 {
  if (map2.find(treasure) != map2.end())
  {
   commonTreasures.insert(treasure);
  }
 }
 return commonTreasures;
}

int main()
{
 set<int> pirateMap1 = {10, 20, 30, 40, 50};
 set<int> pirateMap2 = {30, 40, 60, 70, 50};

 set<int> common = findCommonTreasures(pirateMap1, pirateMap2);

 cout << "Common treasures: ";
 for (int treasure : common)
  cout << treasure << " ";

 return 0;
}
