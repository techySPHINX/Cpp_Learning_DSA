#include <iostream>
#include <unordered_map>
#include <string>

bool isIsomorphic(std::string s, std::string t) {
 if (s.length() != t.length()) {
  return false;
 }

 std::unordered_map<char, char> mapST, mapTS;

 for (int i = 0; i < s.length(); ++i) {
  char c1 = s[i];
  char c2 = t[i];

  if (mapST.find(c1) != mapST.end()) {
   if (mapST[c1] != c2) {
    return false;
   }
  } else {
   mapST[c1] = c2;
  }

  if (mapTS.find(c2) != mapTS.end()) {
   if (mapTS[c2] != c1) {
    return false;
   }
  } else {
   mapTS[c2] = c1;
  }
 }

 return true;
}

int main() {
 std::string s = "egg";
 std::string t = "add";

 if (isIsomorphic(s, t)) {
  std::cout << s << " and " << t << " are isomorphic." << std::endl;
 } else {
  std::cout << s << " and " << t << " are not isomorphic." << std::endl;
 }

 return 0;
}
