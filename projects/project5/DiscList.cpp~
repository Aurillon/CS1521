#include "DiscList.h"


DiscList::DiscList() {
}

DiscList::~DiscList() {
   std::cout << "DiscList Deconstructor Called" << std::endl;
}

bool DiscList::isEmpty() const {
   return !discListPtr->isEmpty();
}
int DiscList::getNumberOfDiscs() const {
   return discListPtr->getLength();
}

bool DiscList::insertDisc(std::shared_ptr<Disc> aDiscPtr) {
   return (discListPtr->insert(getNumberOfDiscs() + 1, aDiscPtr));
}

bool DiscList::removeDisc(std::weak_ptr<Disc> aDiscPtr) {
   return discListPtr->remove(findDiscPosistion(aDiscPtr));
}

std::weak_ptr<Disc> DiscList::retrieveDisc(int number) const {
   std::weak_ptr<Disc> weakListPtr = discListPtr->getEntry(number);
   return weakListPtr;
}

int DiscList::findDiscPosistion(std::weak_ptr<Disc> aDiscPtr) const {
   std::string title = aDiscPtr.lock()->getTitle();
   int tracks = aDiscPtr.lock()->getNumberOfTracks();
   int length = getNumberOfDiscs();
   for(int i(1); i <= length; ++i) {
      std::weak_ptr<Disc> obj2 = retrieveDisc(i);
      if(title == obj2.lock()->getTitle() && tracks == obj2.lock()->getNumberOfTracks()) {
         return i;
      }
   }
   return -1;
}
