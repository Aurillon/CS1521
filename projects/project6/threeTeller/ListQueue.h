/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2019
 *
 *  Header file for an implementation of the ADT queue that has a
 *  list.
 *
 *  Adapted from pages 418-419 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 03 Apr 2019
 *
 *  @version 7.0 */

#ifndef LIST_QUEUE_
#define LIST_QUEUE_

#include <memory>

#include "QueueInterface.h"
#include "LinkedList.h"

/** @class ListQueue ListQueue.h "ListQueue.h"
 *
 *  Specification of an ADT queue that has a list. */
template <typename ItemType>
class ListQueue : public QueueInterface<ItemType> {
  private:
   std::unique_ptr<LinkedList<ItemType>> listPtr;

  public:
   ListQueue();

   ListQueue(const ListQueue<ItemType>& aQueue);

   virtual ~ListQueue() = default;

   bool isEmpty() const override;

   bool enqueue(const ItemType& newEntry) override;

   bool dequeue() override;

   ItemType peekFront() const override;
};

#include "ListQueue.cpp"

#endif
