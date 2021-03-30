#include "Item.cpp"
#include "Project2.h"

//Constructors
Inventory::Inventory(int init_cap) {
   itemArr = new Item[init_cap];
   recipts = new bool[init_cap];
   cap = init_cap;
   for(int i = 0; i < cap; i++) {
      recipts[i] = false;
   }
}

//Setters
int Inventory::addItem(const std::string& name) {
   int i;
   for(i = 0; i < cap; i++) {
      if(recipts[i] == false) {
         Item item(name);
         itemArr[i] = item;
         return i;
      }
   }

   if(i >= cap) {
      resize(cap + 10);
      Item item(name);
      itemArr[i] = item;
   }
   return i;
}

void Inventory::addRecipt(const int& hash) {
   recipts[hash] = true;
}

void Inventory::addItems(const std::string& name) {
   addRecipt(addItem(name));
}

//Dosomething Functions
std::string Inventory::removeItem(const int& Hash) {
   if(recipts[Hash] == true) {
      return "Removed: " + remove(Hash).getName();
   }
   else {
      return "Nothing to be removed at Hash";
   }
}

Item Inventory::remove(const int Hash) {
   recipts[Hash] = false;
   return itemArr[Hash];
}

//Misc Functions
void Inventory::resize(int new_cap) {
   if(cap == new_cap) {
      return;
   }
   else {
      //std::cout << "Resize Function Called" << std::endl;
      bool *new_recipts = new bool[new_cap];
      Item *new_itemArr = new Item[new_cap];
      for(int i = 0; i < cap; i++) {
         new_itemArr[i] = itemArr[i];
         new_recipts[i] = recipts[i];
      }

      delete []itemArr;
      delete []recipts;
      recipts = new_recipts;
      itemArr = new_itemArr;
      for(int i = cap; i < new_cap; i++) {
         recipts[i] = false;
      }
      cap = new_cap;
   }
}
bool Inventory::contains(const std::string& target) const {
   for(int i = 0; i < cap && recipts[i] != false; i++) {
      if(itemArr[i].getName() == target) {
         return true;
      }
   }
   return false;
}

int Inventory::getFreqOf(const std::string& target) const {
   int count = 0;
   for(int i = 0; i < cap && recipts[i] != false; i++) {
      if(itemArr[i].getName() == target) {
         count++;
      }
   }
   return count;
}

void Inventory::display() const{
   std::cout << "Recipt" << "\t[I] " << "  ItemName" << std::endl;
   std::cout << "----------------------" << std::endl;
   for(int i = 0; i < cap; i++) {
      if(recipts[i] == true) {
         std::cout << "[" << recipts[i] << "]" << "\t[" << i << "]\t"
                   << itemArr[i].getName() << std::endl;
      }
   }
}

void Inventory::clear() {
   delete []itemArr;
   itemArr = new Item[MAX];
   cap = MAX;
   for(int i = 0; i < cap; i++) {
      recipts[i] = false;
   }
}

int Inventory::getSize() const {
   int count = 0;
   for(int i = 0; i < cap; i++) {
      if(recipts[i] == true) {
         count++;
      }
   }
   return count;
}

int Inventory::getCap() const {
   return cap;
}

bool Inventory::isEmpty() const {
   for(int i = 0; i < cap && recipts[i] == true; i++) {
      return false;
   }
   return true;
}
