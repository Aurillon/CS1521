#include "lab2function.cpp"

int main(){
   std::cout << "==== TEST BLOCK 1 ====" << std::endl;
   writeLine("Y6bs*", 9);
   writeLine("*", -2);
   writeLine("", 0);
   writeLine("$", 1);
   writeLine("747", 20);

   std::cout << "==== TEST BLOCK 2 ====" << std::endl;
   //std::cout << "Negative Chars per line" << std::endl;
   writeLine("*", -5, -2);
   //std::cout << "Zero Chars per line" << std::endl;
   writeLine("", 5, -2);
   //std::cout << "One Char per line" << std::endl;
   writeLine("$", 5, -2);
   //std::cout << "more then p
   writeLine("a^", 5, -2);

   std::cout << "==== TEST BLOCK 3 ====" << std::endl;
   writeLine("*", -5, 0);
   writeLine("", 5, 0);
   writeLine("$", 5, 0);
   writeLine("a%", 5, 0);

   std::cout << "==== TEST BLOCK 4 ====" << std::endl;
   writeLine("*", -5, 2);
   writeLine("", 5, 2);
   writeLine("$", 5, 2);
   writeLine("a!", 5, 2);

   return 0;
}
