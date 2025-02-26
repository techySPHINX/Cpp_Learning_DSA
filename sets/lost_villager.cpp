#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findMissingVillagers(vector<int> &all_villagers, vector<int> &present_villagers)
{
 unordered_set<int> presentSet(present_villagers.begin(), present_villagers.end());
 vector<int> missingVillagers;

 for (int villager : all_villagers)
 {
  if (presentSet.find(villager) == presentSet.end())
   missingVillagers.push_back(villager);
  }
 }

 return missingVillagers;
}

int main()
{
 vector<int> all_villagers = {101, 102, 103, 104, 105};
 vector<int> present_villagers = {101, 103, 105};

 vector<int> missing = findMissingVillagers(all_villagers, present_villagers);

 cout << "Missing villagers: ";
 for (int id : missing)
 {
  cout << id << " ";
 }

 return 0;
}
