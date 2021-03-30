#include "isPalindrome.h"
#include "PrecondViolatedExcep.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"

bool isPalindrome(const std::string& stringToCheck) {
   LinkedQueue<char> aQueue;
   LinkedStack<char> aStack;
   int length = stringToCheck.length();

   // std::cout << "stringToCheck: " << stringToCheck << std::endl;
   for(int i(0); i< length; ++i) {
      aQueue.enqueue(stringToCheck[i]);
      aStack.push(stringToCheck[i]);
   }

   bool charAreEqual = true;
   while(!aQueue.isEmpty() && charAreEqual) {
      //std::cout << "Front of Queue: " << Queue.peekFront() << std::endl;
      //std::cout << "Front of Stack: " << Stack.peek() << std::endl;
      if(aQueue.peekFront() == aStack.peek()) {
         aQueue.dequeue();
         aStack.pop();
      }
      else {
         charAreEqual = false;
      }
   }

   return charAreEqual;;
}
