#include <iostream>
#include <string>
#include <unordered_map>

char getMaxOccurringChar(const std::string& str) {
 std::unordered_map<char, int> charCount;
 for (char ch : str) {
  charCount[ch]++;
 }

 char maxChar = '\0';
 int maxCount = 0;
 for (const auto& pair : charCount) {
  if (pair.second > maxCount) {
   maxCount = pair.second;
   maxChar = pair.first;
  }
 }

 return maxChar;
}

int main() {
 std::string input;
 std::cout << "Enter a string: ";
 std::getline(std::cin, input);

 char result = getMaxOccurringChar(input);
 std::cout << "The maximum occurring character is: " << result << std::endl;

 return 0;
}
