/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2019
 *
 *  Implementation file for the class LinkedSet.
 *
 *  Adapted from pages 139-148 in Carrano 7e.
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
LinkedSet<ItemType>::LinkedSet(const LinkedSet<ItemType>& aSet) {

   itemCount = aSet.itemCount;

   if (!aSet.headPtr) { // if (aSet.headPtr == nullptr) {
      headPtr = nullptr;
   }
   else {
      NodePtr origChainPtr(aSet.headPtr);

      headPtr = new Node<ItemType>(origChainPtr->getItem() );

      NodePtr newChainPtr(headPtr);

      origChainPtr = origChainPtr->getNext();

      while (origChainPtr) { // while (origChainPtr != nullptr) {
         newChainPtr->setNext(new
                              Node<ItemType>(origChainPtr->getItem())
                              );

         newChainPtr = newChainPtr->getNext();
         origChainPtr = origChainPtr->getNext();
      }
   }
}

template <typename ItemType>
LinkedSet<ItemType>::~LinkedSet() {

   //clear();
}

template <typename ItemType>
int LinkedSet<ItemType>::getCurrentSize() const {

   return itemCount;
}

template <typename ItemType>
bool LinkedSet<ItemType>::isEmpty() const {

   return itemCount == 0;
}

template <typename ItemType>
bool LinkedSet<ItemType>::add1(const ItemType& newEntry) {
   headPtr = new Node<ItemType>(newEntry,
                                headPtr);

   ++itemCount;
   return true;
}


template <typename ItemType>
bool LinkedSet<ItemType>::add(const ItemType& newEntry) {
   if(!contains(newEntry)) {
      headPtr = new Node<ItemType>(newEntry,
                                   headPtr);

      ++itemCount;
      return true;
   }
   return false;
}

template <typename ItemType>
bool LinkedSet<ItemType>::remove(const ItemType& anEntry) {

   NodePtr entryNodePtr(getPointerTo(anEntry) );

   bool canRemoveEntry(entryNodePtr); // bool
   canRemoveEntry = (entryNodePtr != nullptr);

   if (canRemoveEntry) {
      entryNodePtr->setItem(headPtr->getItem() );

      NodePtr nodeToDeletePtr(headPtr);

      headPtr = headPtr->getNext();

      delete nodeToDeletePtr;

      --itemCount;
   }

   return canRemoveEntry;
}

template <typename ItemType>
Node<ItemType>* LinkedSet<ItemType>::getPointerTo(const ItemType&
                                                  target) const {

   bool isFound(false);

   NodePtr curPtr(headPtr);

   while (!isFound && curPtr) { // ... && curPtr != nullptr) {
      isFound = curPtr->getItem() == target;

      if (!isFound) { // Must protect curPtr as it is returned
         curPtr = curPtr->getNext();
      }
   }

   return curPtr;
}

template <typename ItemType>
void LinkedSet<ItemType>::clear() {

   NodePtr nodeToDeletePtr(headPtr);

   while (headPtr) { // while (headPtr != nullptr) {
      headPtr = headPtr->getNext();

      delete nodeToDeletePtr;

      nodeToDeletePtr = headPtr;
   }
   // Note that headPtr == nodeToDeletePtr == nullptr
   itemCount = 0;
}

template <typename ItemType>
bool LinkedSet<ItemType>::contains(const ItemType& anEntry) const {

   return getPointerTo(anEntry); // ... != nullptr;
}

template <typename ItemType>
int LinkedSet<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{

   int frequency(0);

   NodePtr curPtr(headPtr);

   while (curPtr) { // ... != nullptr) {
      if (curPtr->getItem() == anEntry) {
         ++frequency;
      }

      curPtr = curPtr->getNext();
   }

   return frequency;
}

template <typename ItemType>
std::vector<ItemType> LinkedSet<ItemType>::toVector() const {

   std::vector<ItemType> setContents;

   NodePtr curPtr(headPtr);

   while (curPtr) { // ... != nullptr) {
      setContents.push_back(curPtr->getItem() );

      curPtr = curPtr->getNext();
   }

   return setContents;
}

template <typename ItemType>
LinkedSet<ItemType> LinkedSet<ItemType>::difference(const LinkedSet<ItemType>& aSet) const {

   LinkedSet<ItemType> misspelled;
   NodePtr curPtr(aSet.headPtr);
   std::string item;
   while(curPtr) {
      item = curPtr->getItem();
      if(!contains(item)) {
         //std::cout << item << std::endl;
         misspelled.add(item);
      }
      curPtr = curPtr->getNext();
   }
   return misspelled;
}
