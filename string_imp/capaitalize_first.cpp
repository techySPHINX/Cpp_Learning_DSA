#include <iostream>
#include <cctype>
#include <string>

void capitalizeFirstLetter(std::string &str) {
 bool capitalize = true;

 for (char &ch : str) {
  if (std::isspace(ch)) {
   capitalize = true;
  } else if (capitalize && std::isalpha(ch)) {
   ch = std::toupper(ch);
   capitalize = false;
  } else {
   ch = std::tolower(ch);
  }
 }
}

int main() {
 std::string input;
 std::cout << "Enter a string: ";
 std::getline(std::cin, input);

 capitalizeFirstLetter(input);

 std::cout << "Capitalized string: " << input << std::endl;

 return 0;
}
