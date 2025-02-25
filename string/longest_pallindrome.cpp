#include <iostream>
#include <string>

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.length() <= 1) {
      return s;
    }

    string lps = "";  // Initialize longest palindromic substring

    for (int i = 1; i < s.length(); i++) {
      // Check for even-length palindromes centered at i
      int low = i - 1;
      int high = i;
      while (low >= 0 && high < s.length() && s[low] == s[high]) {
        low--;
        high++;
      }
      string candidate = s.substr(low + 1, high - low - 1);
      if (candidate.length() > lps.length()) {
        lps = candidate;
      }

      // Check for odd-length palindromes centered at i and i+1
      low = i - 1;
      high = i + 1;
      while (low >= 0 && high < s.length() && s[low] == s[high]) {
        low--;
        high++;
      }
      candidate = s.substr(low + 1, high - low - 1);
      if (candidate.length() > lps.length()) {
        lps = candidate;
      }
    }

    return lps;
  }
};

int main() {
  std::string str = "babad";
  
  std::string longest_palindrome = longestPalindrome(str);
  std::cout << "Longest Palindrome: " << longest_palindrome << std::endl;
  return 0;
}

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         if (s.length() <= 1) {
//             return s;
//         }

//         string lps = "";

//         for (int i = 1; i < s.length(); i++) {
//             int low = i;
//             int high = i;

//             while (s[low] == s[high]) {
//                 low--;
//                 high++;

//                 if (low == -1 || high == s.length())
//                     lps = "";
//                 break;
//             }

//             string pallindrome = s.substr(low + 1, high);

//             if (pallindrome.length() > lps.length()) {
//                 lps = pallindrome;
//             }

//             low = i - 1;
//             high = i;

//             while (s[low] == s[high]) {
//                 low--;
//                 high++;

//                 if (low == -1 || high == s.length())
//                     lps = "";
//                 break;

//                 string pallindrome = s.substr(low + 1, high);

//                 if (pallindrome.length() > lps.length()) {
//                     lps = pallindrome;
//                 }
//             }
//             return lps;
//         }
//     }
// };