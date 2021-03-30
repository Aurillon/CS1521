/** @file
    0;136;0c *
    *  @course CS1521
    *  @section 1
    *  @term Spring 2019
    *
    *  Implementation file for the class Arrayset.
    *
    *  Adapted from pages 101-111 in Carrano 7e.
    *
    *  @author Frank M. Carrano
    *  @author Timothy Henry
    *  @author Steve Holtz
    *
    *  @date 05 Feb 2019
    *
    *  @version 7.0 */

#include <vector>

template <typename ItemType>
int ArraySet<ItemType>::getCurrentSize() const {

   return itemCount;
}

template <typename ItemType>
bool ArraySet<ItemType>::isEmpty() const {

   return !itemCount; // itemCount == 0;
}

template <typename ItemType>
bool ArraySet<ItemType>::add(const ItemType& newEntry) {

   bool hasRoomToAdd(itemCount < maxItems && !contains(newEntry));

   if (hasRoomToAdd) {
      items[itemCount] = newEntry;
      ++itemCount;
   }

   return hasRoomToAdd;
}

template <typename ItemType>
bool ArraySet<ItemType>::remove(const ItemType& anEntry) {

   int locatedIndex(getIndexOf(anEntry) );
   bool canRemoveItem(!isEmpty() && locatedIndex > -1);

   if (canRemoveItem) {
      --itemCount;
      items[locatedIndex] = items[itemCount];
   }

   return canRemoveItem;
}

template <typename ItemType>
void ArraySet<ItemType>::clear() {

   itemCount = 0;
}

template <typename ItemType>
bool ArraySet<ItemType>::contains(const ItemType& anEntry) const {

   bool isFound(false);
   int curIndex(0);

   while (!isFound && curIndex < itemCount) {
      isFound = anEntry == items[curIndex];
      ++curIndex; // Does not matter if extra increment occurs
   }

   return isFound;
}

template <typename ItemType>
int ArraySet<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{

   int frequency(0);
   int curIndex(0);

   while (curIndex < itemCount) {
      if (items[curIndex] == anEntry) {
         ++frequency;
      }
      ++curIndex;
   }

   return frequency;
}

template <typename ItemType>
std::vector<ItemType> ArraySet<ItemType>::toVector() const {

   std::vector<ItemType> bagContents;

   for (int i(0); i < itemCount; ++i) {
      bagContents.push_back(items[i]);
   }

   return bagContents;
}

template <typename ItemType>
int ArraySet<ItemType>::getIndexOf(const ItemType& target) const {

   bool isFound(false);
   int targetIndex(-1);
   int searchIndex(0);

   while (!isFound && searchIndex < itemCount) {
      isFound = items[searchIndex] == target;

      if (isFound) {
         targetIndex = searchIndex;
      }
      ++searchIndex; // Does not matter if extra increment occurs
   }

   return targetIndex;
}

template <typename ItemType>
ArraySet<ItemType> ArraySet<ItemType>::difference(const ArraySet<ItemType>& set2) const{

   ArraySet<ItemType> setItems;

   int index = 0;
   ItemType target;

   while(index < itemCount) {
      target = items[index];
      if(set2.contains(target) && contains(target)) {
         if(getFrequencyOf(target) > set2.getFrequencyOf(target)) {
            setItems.add(target);
         }
      }
      else if(!set2.contains(target)) {
         setItems.add(target);
      }
      ++index;
   }
   return setItems;
}
