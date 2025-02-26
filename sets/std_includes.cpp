#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool isSubset(set<int> &grandmasterSpells, set<int> &apprenticeSpells){
 return includes(grandmasterSpells.begin(), grandmasterSpells.end(), apprenticeSpells.begin(), apprenticeSpells.end());
}

int main()
{
 set<int> grandMasterSpells = {1, 3, 5, 7, 9, 11};
 set<int> apprenticeSpells = {3, 5, 9};

 if (isSubset(grandMasterSpells, apprenticeSpells))
 {
  cout << "The apprentice's spells are a subset of the Grand Master's book!" << endl;
 }
 else
 {
  cout << "The apprentice's spells contain unknown magic!" << endl;
 }

 return 0;
}
