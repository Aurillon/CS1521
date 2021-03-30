#ifndef DISC_LIST_
#define DISC_LIST_

#include <memory>
#include "LinkedList.h"
#include "Track.h"
//#include "Disc.cpp"

class DiscList {
  public:
   DiscList();
   ~DiscList();
   bool isEmpty() const;
   int getNumberOfDiscs() const;
   bool insertDisc(std::shared_ptr<Disc> aDiscPtr);
   bool removeDisc(std::weak_ptr<Disc> aDiscPtr);
   std::weak_ptr<Disc> retrieveDisc(int number) const;

  private:
   //LinkedList<std::_ptr<Disc>> discList;
   std::unique_ptr<LinkedList<std::shared_ptr<Disc>>> discListPtr = std::make_unique<LinkedList<std::shared_ptr<Disc>>>();
   int findDiscPosistion(std::weak_ptr<Disc> discPtr) const;
};

#endif
