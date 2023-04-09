#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// case A
void numberToDecimal(string number, int base) {
  int len = number.size();
  int decimal = 0;

  for (int i = len - 1; i >= 0; i--) {
    if (number[i] >= '0' && number[i] <= '9') {
      decimal += (int(number[i]) - 48) * 16;
      base *= 16;
    }

    else if (number[i] >= 'A' && number[i] <= 'F') {
      decimal += (int(number[i]) - 55) * 16;
      base *= 16;
    }
  }
  cout << "The value " << number << " is base " << base << " in decimal "
       << endl;
}

// also case A using built-in functions
void numToDec(string number, int base) {
  int result = stoi(number, 0, base);
  cout << "The value " << number << " in base " << base << " is " << result
       << " in decimal " << endl;
}

// case B dec to base
void decimalToBase(int decimal, int base) {
  string bases = "0123456789ABCDEF";
  string result = "";
  int numOut = decimal;
  if (isdigit(decimal) == false) {
    cout << "invalid input" << endl;
  } else {
    while (decimal > 0) {
      result = bases[decimal % base] + result;
      decimal /= base;
    }
    cout << "The decimal value " << numOut << " is " << result << " in"
         << " base " << base << endl;
  }
}

// case C
void binaryToBase(string binaryNumber, int base, int outputBase) {
  int binToDec = stoi(binaryNumber, 0, base);
  cout << "The value " << binaryNumber << "in base " << base << " is "
       << binToDec << " in decimal" << endl;

  cout << "The value " << binaryNumber << " is " << binaryNumber << " in base "
       << outputBase << endl;
}

int main() {
  // intitalize variables
  char userInput;
  bool exit = false;

  string decimal;
  string result;
  int number;

  string binary;
  int base;
  int outputBase;

  // main menu
  cout << "Please enter what you would like to do:" << endl;
  cout << "\t a. Convert a number to decimal (enter a value & given base)"
       << endl;
  cout << "\t b. Convert a decimal to another base (enter a decimal value and "
          "a base)"
       << endl;
  cout << "\t c. Convery a number from base1 to base2 (enter number, base1 and "
          "base2)"
       << endl;
  cout << "\t q. Quit" << endl;
  cout << "Enter your choice and press Enter" << endl;

  // loops through until q is hit so intialized a exit variable in case q is hit
  while (exit == false) {
    // user input
    cin >> userInput;
    // convert user input to upper for main menu
    userInput = toupper(userInput);

    switch (userInput) {
    case 'A':

      cout << "Enter your input value: " << endl;
      cin >> decimal;
      cout << "Enter given base value: " << endl;
      cin >> base;

      // numberToDecimal(decimal, base);
      numToDec(decimal, base);
      break;

    case 'B':

      cout << "Enter your decimal value: " << endl;
      cin >> number;
      cout << "Enter resulting base value: " << endl;
      cin >> base;

      decimalToBase(number, base);
      break;

      // binary to base and output base
    case 'C':

      cout << "Enter your input value: " << endl;
      cin >> binary;
      cout << "Enter original base: " << endl;
      cin >> base;
      cout << "Enter output base: " << endl;
      cin >> outputBase;

      binaryToBase(binary, base, outputBase);
      break;

    case 'Q':
      exit = true;
      break;

    default:
      cout << "Invalid input try again" << endl;
      break;
    }
  }
}
