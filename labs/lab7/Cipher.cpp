#include "Cipher.h"

Cipher::Cipher(): output{""} {
}

void Cipher::print() const {
   std::cout << output << std::endl;
}

char Cipher::encryptRot13(int value) {
   if((value >= 65 && value < 78) || (value >= 97 && value < 110)) {
      return (char)(value + 13);
   }
   else {
      return (char)(value - 13);
   }
   return '*';
}

char Cipher::encryptRot5(int value) {
   if(value >= 48 && value <= 52) {
      return (char)(value + 5);
   }
   else {
      return (char)(value - 5);
   }
   return '*';
}

char Cipher::encrypt(char ch) {
   int value = (int)ch;
   if((value >= 48 && value <= 57)) {
      return encryptRot5(value);
   }
   else if((value >= 65 && value <= 90) || (value >= 97 && value<=122)) {
      return encryptRot13(value);
   }
   else {
      return ch;
   }
}

void Cipher::operator()(char ch) {
   output += encrypt(ch);
}
