#include "lab2function.h"
#include <iostream>




void writeLine(std::string str, int num){
   int length = str.length();
   if(num <= 0){
      // std::cout << "strLeng: " << str.length() << std::endl;
      if(length < 1 || num < 0){
         return;
      }
      else{
         std::cout << "" << std::endl;
      }
   }
   else{
      if(length > num){
         str = str.erase(num, length);
         writeLine(str, num);
      }
      else if(num >= length) {
         std::cout << str;
         writeLine(str, (num - length));
      }
      /* else if((num % length) >= 1){
         std::cout << str;
         writeLine(str,(num - length));
         }
      */
      else{
         std::cout << str[0];
         writeLine(str, (num - 1));
      }
   }
}

void writeLine(std::string str, int num, int lines){
   if(lines <= 0 || str.length() < 1 || num <= 0){
      return;
   }
   else{
      for(int i = 0; i < lines; i++){
         writeLine(str, num);
      }
   }
}
