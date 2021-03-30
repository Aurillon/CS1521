#ifndef ITEM__
#define ITEM__

class Item {
  public:
   //Default Constructor
   Item();

   /** Constutor to create item a provided name
    */
   Item(std::string);

   /** Sets the amount of the Item object.
       @param Amount. Int to save into Amount variable.
       @post if set works amount contains passed int.
    */
   void setAmt(int);

   /** Sets the name of the Item object.
       @param Name. String to save into Name variable.
       @post Item object has name that was passed to function.
    */
   void setName(std::string);

   /** Returns the int in Amount variable.
       @return Amount variable.
    */
   int getAmt();

   /** Returns the string in Name variable.
       @return Name variable.
    */
   std::string getName();

   /** Displays the values of Name and Amount
    */
   void display();

  private:
   std::string Name;
   int Amount;

};

#endif
