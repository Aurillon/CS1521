#ifndef CIPHER_
#define CIPHER_

#include <iostream>
#include <string>
#include <algorithm>

class Cipher {
  public:
   Cipher();
   void operator()(char);
   void print() const;

  private:
   char encryptRot13(int value);
   char encryptRot5(int value);
   char encrypt(char);
   std::string output;
};

#endif
