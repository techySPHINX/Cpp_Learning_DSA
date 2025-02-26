#include <iostream>
#include <unordered_map>

using namespace std;

bool areAnagrams(string word1, string word2){
 if(word1.length() != word2.length()) return false;

 unordered_map<char, int> charCount:
 for(char ch: word1){
  charCount[ch]++;
 }

 for(char ch: word2){
  if(charCount[ch] == 0) return false;
  charCount[ch]--;
 }

 return true;

}

int main(){
 string word1 = "listen";
 string word2 = "silent";

 if (areAnagrams(word1, word2)){
  cout << "yes, they are anagrams" << endl;
 }else{
  cout << "No, they are not anagrams" << endl;
 }

 return 0;
}
