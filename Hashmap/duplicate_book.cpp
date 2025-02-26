#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void findDuplicateBooks(vector<string> &books)
{
 unordered_map<string, int> bookCount;

 for (const string &book : books)
 {
  bookCount[book]++;
 }

 cout << "duplicates book names:\n";
 for (const auto &entry : bookCount)
 {
  if (entry.second > 1)
  {
   cout << entry.first << " > " << entry.second << " times\n";
  }
 }
}

int main()
{
 vector<string> books = {"Harry Potter", "Lord of the Rings", "Harry Potter", "Sherlock Holmes", "Harry Potter", "Lord of the Rings"};

 findDuplicateBooks(books);

 return 0;
}
