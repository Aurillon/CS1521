/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2019
 *
 *  Header file for a linked implementation of the ADT bag.
 *
 *  Adapted from page 139 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 05 Feb 2019
 *
 *  @version 7.0 */

#ifndef LINKED_SET_
#define LINKED_SET_

#include <vector>

#include "SetInterface.h"
#include "Node.h"

/** @class LinkedSet LinkedSet.h "LinkedSet.h"
 *
 *  Specification of a pointer-based ADT set. */
template <typename ItemType>
class LinkedSet : public SetInterface<ItemType> {
  private:
   using NodePtr = Node<ItemType>*;

   /** Pointer to first node. */
   NodePtr headPtr = nullptr;

   /** Number of items in this set. */
   int itemCount = 0;

   /** Gets a pointer to the node containing the target in this set.
    *
    * @pre None.
    *
    * @post None.
    *
    * @param target The ItemType value to find.
    *
    * @return A pointer to the node that contains the given target or
    *         nullptr if the bag does not contain the target. */
   NodePtr getPointerTo(const ItemType& target) const;

  public:
   /** Default constructor. */
   LinkedSet() = default;

   /** Copy constructor. */
   LinkedSet(const LinkedSet<ItemType>& aSet);

   virtual ~LinkedSet();

   virtual int getCurrentSize() const;

   virtual bool isEmpty() const;

   virtual bool add1(const ItemType& newEntry);
   
   virtual bool add(const ItemType& newEntry);

   virtual bool remove(const ItemType& anEntry);

   virtual void clear();

   virtual int getFrequencyOf(const ItemType& anEntry) const;

   virtual bool contains(const ItemType& anEntry) const;

   virtual LinkedSet<ItemType> difference(const LinkedSet<ItemType>& aSet) const;

   virtual std::vector<ItemType> toVector() const;
};

#include "LinkedSet.cpp"

#endif
