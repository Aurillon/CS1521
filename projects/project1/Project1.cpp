#include "Project1.h"
#include <iostream>
#include <string>
#include <regex>

Seq::Seq(){
   small = 0.0;
   large = 0.0;
   total = 0.0;
   last = 0.0;
   length = 0;
}

void Seq::add(const double& Value){
   if(length == 0){
      setSmall(Value);
      setLarge(Value);
   }
   else{

      if(Smallest() > Value){
         setSmall(Value);
         //std::cout << "Small changed to: " << Smallest() << std::endl;
      }
      else if(Largest() < Value) {
         setLarge(Value);
         //std::cout << "Large changed to: " << Largest() << std::endl;
      }
      else {
         //std::cout << "Nothing changed" << std::endl;
         //std::cout << "Value entered: " << Value << "\n";
         //std::cout << "Small: " << Smallest() << "\nLarge: " << Largest() << std::endl;
      }
   }
   setTotal(Value);
   setLast(Value);
   setlength();
}

void Seq::add(double values[], int n){
   for(int i = 0; i < n; i++){
      add(values[i]);
   }
}

void Seq::add(){
   bool noChars;
   std::string value;
   std::regex checkSum("^Quit$");
   std::string::size_type sz;
   std::cout << "Enter a number to add or Type Quit to quit" << std::endl;
   std::cin >> value;
   while(!std::regex_match(value, checkSum)){
      noChars = std::regex_match(value, std::regex("^[A-Za-z]+$"));
      if(noChars){
         std::cout << "Invalid Input" << std::endl;
      }
      else {
         add(std::stod(value, &sz));
      }
      std::cin >> value;
   }
}

void Seq::add(const float& Value){
   add((double)Value);
}

//Setters
void Seq::setlength(){
   length++;
}
void Seq::setLength(const int& Value){
   length = Value;
}
void Seq::setLast(const double& Value){
   last = Value;
}
void Seq::setTotal(const double& Value){
   total += Value;
}

void Seq::setSmall(const double& Value){
   small = Value;
}

void Seq::setLarge(const double& Value){
   large = Value;
}

//Getters
int Seq::Length(){
   return length;
}

double Seq::TotalValue(){
   return total;
}

double Seq::lastSeq(){
   if(length > 0){
      return last;
   }
   else{
      // std::cerr << "LastSeq Called" << std::endl;
      std::cerr << "Length is Zero cant call lastSeq Func" << std::endl;
   }
}

double Seq::Mean(){
   if(length > 0){
      return (total / length);
   }
   else {
      //std::cerr << "Mean Called" << std::endl;
      std::cerr << "Length is Zero cant call Mean Func" << std::endl;
   }
}

double Seq::Smallest(){
   if(length > 0) {
      return small;
   }
   else {
      //std::cerr << "Smallest Called" << std::endl;
      std::cerr << "Length is Zero cant call Smallest Func" << std::endl;
   }
}

double Seq::Largest() {
   if(length > 0) {
      return large;
   }
   else {
      //std::cerr << "Largest Called" << std::endl;
      std::cerr << "Length is Zero cant call Largest Func" << std::endl;
   }
}

void Seq::clear() {
   small = 0.0;
   large = 0.0;
   total = 0.0;
   last = 0.0;
   length = 0;
}

void Seq::display(){
   if(Length() > 0){
      std::cout << "Length: " << Length() << "\n";
      std::cout << "Last number in the Sequence: " << lastSeq() << "\n";
      std::cout << "Total Value of the Sequence: " << TotalValue() << "\n";
      std::cout << "Mean of the Sequence: " << Mean() << "\n";
      std::cout << "Smallest value in Sequence: " << Smallest() << "\n";
      std::cout << "Largest Value in Sequence: " << Largest() << std::endl;
   }

   else {
      std::cout << "Length: " << length << "\n";
      std::cout << "Total Value of the Sequence: " << last << "\n";
      std::cout << "Length is zero, cant call other Functions" << std::endl;
   }
}
