#include <iostream>
#include <cmath>
#include <limits>
#include <string>

using namespace std;

int binaryToDecimal(long long binary) {
  int decimal = 0;
  int base = 1;
  int rem;

  while (binary != 0) {
    rem = binary % 10;
    if (rem < 0 || rem > 1) {
      cerr << "Invalid binary input." << endl;
      return numeric_limits<int>::min();
    }
    decimal += rem * base;
    base *= 2;
    binary /= 10;
  }

  return decimal;
}


string decimalToBinary(int decimal) {
  string binary;

  if (decimal == 0) {
    return "0";
  }

  while (decimal > 0) {
    binary = (decimal % 2 == 0 ? "0" : "1") + binary;
    decimal /= 2;
  }

  return binary;
}

string decimalToOctal(int decimal) {
  string octal;

  if (decimal == 0) {
    return "0";
  }

  while (decimal > 0) {
    int remainder = decimal % 8;
    octal = to_string(remainder) + octal;
    decimal /= 8;
  }

  return octal;
}

// Function to convert decimal to hexadecimal
string decimalToHexadecimal(int decimal) {
  string hexadecimal;
  const char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                            '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

  if (decimal == 0) {
    return "0";
  }

  while (decimal > 0) {
    int remainder = decimal % 16;
    hexadecimal = hexDigits[remainder] + hexadecimal;
    decimal /= 16;
  }

  return hexadecimal;
}

int main() {
  long long binary;
  int decimal;

  cout << "Enter a binary number: ";
  cin >> binary;

  decimal = binaryToDecimal(binary);

  if (decimal != numeric_limits<int>::min()) { // Check for error from binaryToDecimal
    cout << binary << " in binary = " << decimal << " in decimal" << endl;

    cout << decimal << " in decimal = " << decimalToBinary(decimal) << " in binary" << endl;
    cout << decimal << " in decimal = " << decimalToOctal(decimal) << " in octal" << endl;
    cout << decimal << " in decimal = " << decimalToHexadecimal(decimal) << " in hexadecimal" << endl;
  }

  return 0;
}
