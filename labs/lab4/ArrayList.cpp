/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2019
 *
 *  Implementation file for an array-based implementation of the ADT
 *  list.
 *
 *  Adapted from pages 268-272 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 04 Mar 2019
 *
 *  @version 7.0 */

#include <string>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
bool ArrayList<ItemType>::isEmpty() const {

   return !itemCount;
}

template <typename ItemType>
int ArrayList<ItemType>::getLength() const {

   return itemCount;
}

template <typename ItemType>
bool ArrayList<ItemType>::insert(int newPosition,
                                 const
                                 ItemType& newEntry) {

   bool ableToInsert(newPosition >= 1 &&
                     newPosition <= itemCount + 1
                     &&
                     itemCount < maxItems);

   if (ableToInsert) {
      // Make room for newEntry by shifting all entries at positions
      // >= newPosition toward the end of the array:
      for (int pos(itemCount); pos >= newPosition; --pos) {
         items[pos] = items[pos - 1];
      }

      // Insert new entry:
      items[newPosition - 1] = newEntry;

      ++itemCount;
   }

   return ableToInsert;
}

template <typename ItemType>
bool ArrayList<ItemType>::remove(int position) {

   bool ableToRemove(position >= 1 &&
                     position <= itemCount);

   if (ableToRemove) {
      // Remove entry by shifting all entries after the one at
      // position toward the beginning of the array:
      for (int pos(position); pos < itemCount; ++pos) {
         items[pos - 1] = items[pos];
      }
      --itemCount;
   }

   return ableToRemove;
}

template <typename ItemType>
void ArrayList<ItemType>::clear() {

   itemCount = 0;
}

template <typename ItemType>
ItemType ArrayList<ItemType>::getEntry(int position) const {

   bool ableToGet(position >= 1 &&
                  position <= itemCount);

   if (!ableToGet) {
      //std::string message("ArrayList::getEntry() called with an empty");
      //message += "list or an invalid position.";

      //throw PrecondViolatedExcep(message);
   }

   return items[position - 1];
}

template <typename ItemType>
ItemType ArrayList<ItemType>::replace(int position,
                                      const
                                      ItemType& newEntry) {

   bool ableToSet(position >= 1 &&
                  position <= itemCount);

   if (!ableToSet) {
      //std::string message("ArrayList::setEntry() called with an empty");
      //message += "list or an invalid position.";
      std::cerr << "DONE FUCKED" << std::endl;
      //throw PrecondViolatedExcep(message);
   }

   ItemType oldEntry(items[position - 1]);

   items[position - 1] = newEntry;

   return oldEntry;
}
