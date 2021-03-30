#ifndef _INFIX_
#define _INFIX_

#include "LinkedStack.h"
#include "PrecondViolatedExcep.cpp"
#include <map>
#include <string>

class Infix {
  public:

   //Constructor
   Infix();

   //Deconstructor
   ~Infix();

   //Getters
   std::string getExp() const;
   int evalExp();

   //Setters
   void setExp(std::string& exp);

  private:
   std::string Exp;
};


#endif
