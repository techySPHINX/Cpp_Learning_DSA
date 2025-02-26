#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<string> oragnizeSpellbook(vector<string> &spells)
{
 set<string> uniqueSpells(spells.begin(), spells.end());
 return vector<string>(uniqueSpells.begin(), uniqueSpells.end());
}

int main()
{
 vector<string> spells = {"Fireball", "Ice Storm", "Fireball", "Lightning Bolt", "Ice Storm"};
 vector<string> oragnizeSpells = oraganizeSpellbook(spells);

 cout << "Oragnized Spellbook: ";
 for (const string &spell : organizeSpells)
 {
  cout << spell << " ";
 }

 return 0;
}
