/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2019
 *
 *  Header file for a pointer-based implementation of the ADT stack.
 *
 *  Adapted from page 246, 250 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 06 Mar 2019
 *
 *  @version 7.0 */

#ifndef LINKED_STACK_
#define LINKED_STACK_

#include "StackInterface.h"
#include "Node.h"

/** @class LinkedStack LinkedStack.h "LinkedStack.h"
 *
 *  Specification of a pointer-based ADT stack. */
template <typename ItemType>
class LinkedStack : public StackInterface<ItemType> {
  private:
   using NodePtr = Node<ItemType>*;

   NodePtr topPtr = nullptr;

  public:
   LinkedStack() = default;

   LinkedStack(const LinkedStack<ItemType>& aStack);

   virtual ~LinkedStack();

   virtual bool isEmpty() const;

   virtual bool push(const ItemType& newEntry);

   virtual bool pop();

   virtual ItemType peek() const; // throw(PrecondViolatedExcep);
   // Delete throw clauses.
};

#include "LinkedStack.cpp"

#endif
