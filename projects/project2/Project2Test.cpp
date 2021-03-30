#include <iostream>
#include "Project2.cpp"

int main() {
   Inventory bag;

   std::string name, input;
   std::cout << "Commands: Add, Clear, Remove, Display, Contains,"
             << " FreqOf, Cap, Size, 'Quit' to Quit" <<  std::endl;

   while(input != "Quit") {
      std::cout << "Enter Command: ";
      std::cin >> input;
      input[0] = toupper(input[0]);

      if(input == "Add") {
         std::cout << "Enter one or more items to add to your";
         std::cout << "bag. type 'Done' to quit." << std::endl;
         std::cin >> name;
         while(name != "Done") {
            bag.addItems(name);
            std::cin >> name;
         }
      }
      //auto Testing less work typing in things.
      else if(input == "ADD") {
         name = "HELLO WORLD";

         for(int i = 0; i < 45; i++) {
            bag.addItems(name);
         }

         bag.display();

         for(int i = 0; i < 45; i++) {
            if((i % 2) == 0) {
               std::cout << "\n" << i << ": "
                         << bag.removeItem(i) << std::endl;
            }
         }
         std::cout << "\n" << std::endl;

         bag.display();
         bag.clear();

         std::cout << "\nCleared Bag\n" << std::endl;

         bag.display();
      }
      else if(input == "Clear") {
         bag.clear();
      }

      else if(input == "Remove"){
         if(bag.isEmpty()) {
            std::cout << "Bag is empty nothing to remove." << std::endl;
         }
         else {
            int Value;
            std::cout << "Enter a hash value to remove that Item"
                      << std::endl;
            std::cin >> Value;
            std::cout << bag.removeItem(Value) << std::endl;
         }
      }

      else if(input == "Display") {
         bag.display();
      }

      else if(input == "Quit") {
      }
      else if(input == "Size") {
         std::cout << bag.getSize() << std::endl;
      }
      else if(input == "Cap") {
         std::cout << bag.getCap() << std::endl;
      }

      else if(input == "FreqOf") {
         std::cin >> name;
         std::cout << "There is " << bag.getFreqOf(name) << " of " << name
                   << std::endl;
      }
      else if(input == "Contains") {
         std::cin >> name;
         if(bag.contains(name)) {
            std::cout << "Your bag contains " << name << std::endl;
         }
         else {
            std::cout << name << " is not in your bag." << std::endl;
         }
      }
      else {
         std::cout << "Commands: Add, Clear, Remove, Display, Contains,"
                   << " FreqOf, Cap, Size, 'Quit' to Quit"  << std::endl;
      }
   }
   return EXIT_SUCCESS;
}
