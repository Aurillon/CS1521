/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2019
 *
 *  Implementation file for an implementation of the ADT queue that
 *  has a list.
 *
 *  Adapted from page 399-400 in Carrano 6e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 03 Apr 2019
 *
 *  @version 6.0 */

#include <string>
#include <memory>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
ListQueue<ItemType>::ListQueue()
   : listPtr(std::make_unique<LinkedList<ItemType>>() ) {
}

template <typename ItemType>
ListQueue<ItemType>::ListQueue(const ListQueue<ItemType>& aQueue)
   : listPtr(std::make_unique<LinkedList<ItemType>>(*(aQueue.listPtr))
             ) {
}

template <typename ItemType>
bool ListQueue<ItemType>::isEmpty() const {

   return listPtr->isEmpty();
}

template <typename ItemType>
bool ListQueue<ItemType>::enqueue(const ItemType& newEntry) {

   return listPtr->insert(listPtr->getLength() + 1, newEntry);
}

template <typename ItemType>
bool ListQueue<ItemType>::dequeue() {

   return listPtr->remove(1);
}

template <typename ItemType>
ItemType ListQueue<ItemType>::peekFront() const {

   if (isEmpty() ) {
      std::string message("ListQueue::peekFront() called ");
      message += "on an empty queue.";

      throw PrecondViolatedExcep(message);
   }

   return listPtr->getEntry(1);
}
