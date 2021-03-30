#include "Item.h"

Item::Item() {
}

Item::Item(std::string name) {
   Amount = 1;
   Name = name;
}

void Item::setAmt(int amount) {
   Amount = amount;
}

void Item::setName(std::string name) {
   Name = name;
}

int Item::getAmt() {
   return Amount;
}

std::string Item::getName() {
   return Name;
}

void Item::display() {
   std::cout << getName() << ": " << getAmt() << std::endl;
}
