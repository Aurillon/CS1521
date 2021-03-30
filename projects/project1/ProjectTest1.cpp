#include "Project1.cpp"
#include <stdlib.h>
#include <time.h>
int main(){

   Seq numbers;

   //testing
   std::cout << "==== TEST1: Empty Sequence of Values ====\n\n";
   numbers.clear();
   numbers.display();
   numbers.clear();

   std::cout << "\n\n==== TEST2: A Single Value Sequence ====\n\n";
   numbers.add(1.2);
   numbers.display();
   numbers.clear();

   std::cout << "\n\n==== TEST3: An increasing sequence of values ====\n\n";
   double values[8] = {-3.7,0.0, 1.2, 3.0, 4.5, 6.8, 7.6, 9.2};
   numbers.add(values, 8);
   numbers.display();
   numbers.clear();

   std::cout << "\n\n==== TEST4: A decreasing sequence of values ====\n\n";
   double Values2[9] = {9.2, 8.3, 7.5, 4.8, 3.9, 2.5, 1.3, 0.0, -7.6};
   numbers.add(Values2, 9);
   numbers.display();
   numbers.clear();

   std::cout << "\n\n==== TEST5: A random sequence of values ====\n\n";
   srand(time(NULL));
   double Values3[10];
   for(int i = 0; i < 10; i++){
      int randNum = rand() % 10 + 1;
      double randDec = (rand() % 10 + 1) / 10.0;
      randDec += randNum;
      if(i % 2){
         Values3[i] = randDec;
      }
      else{
         Values3[i] = randDec * -1;
      }
   }
   numbers.add(Values3, 10);
   numbers.display();
   numbers.clear();

   std::cout << "\n\n==== TEST6: A constant sequence of value ====\n\n";
   double Values4[8] = {5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5};
   numbers.add(Values4, 8);
   numbers.display();
   numbers.clear();

   std::cout << "\n\n==== TEST7: Other sequences of interes ====\n\n";
   numbers.add(1.0);
   numbers.add(-1.0);
   numbers.display();
   numbers.clear();

   std::cout << "\n\n==== TEST8: allows adding unlimited values(while loop) ====\n\n";
   numbers.add();
   numbers.display();
   numbers.clear();

   std::cout << "\n\n==== TEST9: Adding floats to Sequence through while loop ====\n\n";
   float Value;
   char opt;
   bool Cont = true;
   while(Cont){
      std::cout << "Enter a number: ";
      std::cin >> Value;
      numbers.add(Value);
      std::cout << "\nEnter 'Q' to quit or 'C' to continue" << std::endl;
      std::cin >> opt;
      if(opt == 'Q'){
         Cont = false;
      }
   }
   numbers.display();
   numbers.clear();

   return 0;
}
