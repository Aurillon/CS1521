/** @ArraySet.h
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2019
 *
 *  Header file for an array-based implementation of the ADT bag.
 *
 *  Adapted from page 100 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 08 Feb 2019
 *
 *  @version 7.0 */

#ifndef ARRAY_SET_
#define ARRAY_SET_

#include <vector>

#include "SetInterface.h"

/** @class ArraySet ArraySet.h "ArraySet.h"
 *
 *  Specification of an array-based ADT Set. */
template <typename ItemType>
class ArraySet : public SetInterface<ItemType> {
  private:
   /** Maximum capacity of this set. */
   static const int DEFAULT_CAPACITY = 6;

   /** Data storage. */
   ItemType items[DEFAULT_CAPACITY];

   /** Number of items in this set. */
   int itemCount = 0;

   /** Maximum capacity of this set. */
   int maxItems = DEFAULT_CAPACITY;

   /** Gets the index of target in the array 'items' in this set.
    *
    * @param target The ItemType value to retrieve the index of.
    *
    * @return The index of the element in the array 'items' that
    *         contains 'target' or -1 if the array does not contain
    *         'target'. */
   int getIndexOf(const ItemType& target) const;

  public:
   /** Default constructor. */
   ArraySet() = default;

   /** Virtual destructor. */
   virtual ~ArraySet() = default;

   /**  Returns itemCount of the ArraySet.
    *
    * @return Int, of how mamy items added to the Set. */
   virtual int getCurrentSize() const;

   /**  Check if Empty.
    *
    * @return bool if no items in container */
   virtual bool isEmpty() const;

   /**  Add item to array.
    *
    * @post Item added to arraySet.
    *
    * @param const ItemType  item to add to array
    *
    * @return bool if item was added succesfully. */
   virtual bool add(const ItemType& newEntry);

   /**  Remove Item from Set.
    * @post if found item is removed.
    *
    * @param anEntry item of ItemType.
    *
    * @return Bool for if succesful removal of item. */
   virtual bool remove(const ItemType& anEntry);

   /**  Clear Set.
    *
    * @post Set is Empty. */
   virtual void clear();

   /**  amount of items in the bag matching target.
    * @param anEntry of ItemType.
    * @return int amount of how many targets. */
   virtual int getFrequencyOf(const ItemType& anEntry) const;

   /**  if Set contains a target.
    * @param parameterName Description of parameter. (Repeat for
    *                      multiple parameters.)
    *
    * @return bool if an entry is found.*/
   virtual bool contains(const ItemType& anEntry) const;

   /**  check for the difference between Sets..
    * @param ArraySet<ItemType>.
    *
    * @return ArraySet<itemType> a container contains items of the difference. */
   virtual ArraySet<ItemType> difference(const ArraySet<ItemType>& set2) const;

   /**  convert arraySet to a vector.
    *
    * @return a vector of type ItemTypw. */
   virtual std::vector<ItemType> toVector() const;
};

#include "ArraySet.cpp"

#endif
