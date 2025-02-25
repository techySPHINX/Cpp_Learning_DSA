#include <iostream>
#include <sstream>
#include <string>

std::string findLongestWord(const std::string& sentence) {
 std::istringstream stream(sentence);
 std::string word;
 std::string longestWord;
 size_t maxLength = 0;

 while (stream >> word) {
  if (word.length() > maxLength) {
   maxLength = word.length();
   longestWord = word;
  }
 }

 return longestWord;
}

std::string findLongestWordWithoutStream(const std::string& sentence) {
 std::string longestWord;
 size_t maxLength = 0;
 size_t start = 0;
 size_t end = 0;

 while (end <= sentence.length()) {
  if (end == sentence.length() || sentence[end] == ' ') {
   size_t wordLength = end - start;
   if (wordLength > maxLength) {
    maxLength = wordLength;
    longestWord = sentence.substr(start, wordLength);
   }
   start = end + 1;
  }
  end++;
 }

 return longestWord;
}

int main() {
 std::string sentence;
 std::cout << "Enter a sentence: ";
 std::getline(std::cin, sentence);

 std::string longestWord = findLongestWord(sentence);
 std::cout << "The longest word is: " << longestWord << std::endl;

 return 0;
}
