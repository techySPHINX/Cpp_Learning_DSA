#include <iostream>
#include <sstream>
#include <string>

int countWords(const std::string& str) {
 std::istringstream stream(str);
 std::string word;
 int count = 0;

 while (stream >> word) {
  ++count;
 }

 return count;
}

int main() {
 std::string sentence;
 std::cout << "Enter a sentence: ";
 std::getline(std::cin, sentence);

 int wordCount = countWords(sentence);
 std::cout << "Number of words: " << wordCount << std::endl;

 return 0;
}
