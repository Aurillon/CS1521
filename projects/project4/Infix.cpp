#include "Infix.h"
#include "preformOperation.cpp"
#include <string>

Infix::Infix() {
   Exp = "";
}

Infix::~Infix() {
}

std::string Infix::getExp() const {
   return Exp;
}

int Infix::evalExp() {
   LinkedStack<int> val_stack;
   LinkedStack<char> op_stack;
   std::map<char, int> op_pres;
   op_pres['+'] = 10;
   op_pres['-'] = 10;
   op_pres['*'] = 20;
   op_pres['/'] = 20;
   op_pres['('] = -1;

   int exp_length = Exp.length();
   for(int i = 0; i < exp_length; ++i) {
      char ch = Exp[i];
      //cout << "input[" << i << "]= " << ch << endl;
      if((int)ch >= (int)'0' && (int)ch <= (int)'9') {
         val_stack.push((int)ch - 48);
      }
      else if(ch == '(') {
         op_stack.push(ch);
      }
      else if(ch == '+' || ch == '-'|| ch == '*' || ch =='/') {
         if(op_stack.isEmpty() || (op_pres[ch] > op_pres[op_stack.peek()])) {
            op_stack.push(ch);
         }
         else {
            while(!op_stack.isEmpty() && (op_pres[ch] <= op_pres[op_stack.peek()])) {
               //std:: cout << "Preform OP called by 2nd case" << std::endl;
               preformOperation(&val_stack, &op_stack);
            }
            //std::cout << "op_stack.peek() = " << op_stack.peek() << std::endl;
            op_stack.push(ch);
         }
      }
      else if(ch == ')') {
         //std::cout << "Prefor OP called by ')' case"  << std::endl;
         preformOperation(&val_stack, &op_stack);
         op_stack.pop();
      }
   }
   //std::cout << "Preform op, called outside main loop" << std::endl;
   preformOperation(&val_stack, &op_stack);
   return val_stack.peek();
}

void Infix::setExp(std::string& exp) {
   Exp = exp;
}
