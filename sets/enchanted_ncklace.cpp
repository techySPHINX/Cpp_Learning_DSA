#include <vector>
#include <iostream>
#include <set>

using namespace std;

void removeDuplicates(vector<int> &necklace){
 set<int> seen;
 vector<int> result;

 for(int gem: necklace){
  if(seen.find(gem) == seen.end()){
   seen.insert(gem);
   result.push_back(gem);
  }
 }
 necklace = result;
}


int main(){
 vector<int> necklcae = {1, 2, 3, 1, 2, 3, 4, 5};
 removeDuplicates(necklcae);

 cout << "Necklace after removing duplicates: ";
 for(int gem: necklcae){
  cout << gem << " ";
 }
 cout << endl;
 return 0;
}
