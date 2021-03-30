#include "preformOperation.h"
#include "PrecondViolatedExcep.h"

void preformOperation(LinkedStack<int>* val_stack, LinkedStack<char>* op_stack) {
   char op = op_stack->peek();
   if(op == '(') {
      return;
   }
   op_stack->pop();
   int RHSop = val_stack->peek();
   val_stack->pop();
   int LHSop = val_stack->peek();
   val_stack->pop();
   if(op == '+') {
      int result = (LHSop + RHSop);
      //std::cout << LHSop << op << RHSop << std::endl;
      val_stack->push(result);
      //std::cout << val_stack->peek() << std::endl;
   }
   else if(op == '-') {
      int result = (LHSop - RHSop);
      //std::cout << LHSop << op << RHSop << std::endl;
      val_stack->push(result);
      //std::cout << val_stack->peek() << std::endl;
   }
   else if(op == '*') {
      //std::cout << LHSop << op << RHSop << std::endl;
      int result = (LHSop * RHSop);
      val_stack->push(result);
      //std::cout << val_stack->peek() << std::endl;
   }
   else if(op == '/') {
      //std::cout << LHSop << op << RHSop << std::endl;
      int result = Divide(LHSop, RHSop);
      val_stack->push(result);
      //std::cout << val_stack->peek() << std::endl;
   }
}

int Divide(int& LHSop, int& RHSop) {
   if(RHSop == 0) {
      std::string message = "Cant Divide by Zero.";
      throw PrecondViolatedExcep(message);
   }
   return (int)(LHSop / RHSop);
}
