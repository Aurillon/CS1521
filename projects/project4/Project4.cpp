#include <iostream>
#include <string>
#include <fstream>

#include "LinkedStack.h"
#include "Infix.cpp"


int main() {
   Infix exp;
   int result;
   std::string input;
   while(std::getline(std::cin, input)) {
      exp.setExp(input);
      try {
         result = exp.evalExp();
         std::cout << input <<"\n" << input << " = " << result <<std::endl;
      }
      catch(const PrecondViolatedExcep& e) {
         std::cerr << "ERROR: " << e.what() << std::endl;
      }
   }



   std::cout << "end of program" << std::endl;
   return 0;
}
