#ifndef INVENTORY__
#define INVENTORY__

class Inventory{
  public:
   //Default Constrotor
   Inventory(int init_cap = MAX);

   /** Adds object to bag.
       @param Name, string to pass to Item constructor.
       @pre none.
       @post if succesful Item and recipt are correctly added.
    */
   void addItems(const std::string&);

   /** Checks for hash in use then removes if its in use.
       @param Hash, of Item to remove from itemArr.
       @return string that gives msg on results of operation.
    */
   std::string removeItem(const int&);

   /** Returns the current number of entries in this bag.
    *
    *  @return The integer number of entries currently in the bag.
    */
   int getSize() const;

   /** Returns the current cap of the bag.
    *
    *  @return The integer cap of items that can be in the bag.
    */
   int getCap() const;

   /** Checks for name match to item in bag.
       @param Name. String to check aganit Item objects.
       @return if found in bag return true, else false.
    */
   bool contains(const std::string&) const;

   /** Gets the amount of a given Item in bag.
       @param Name, the string to check aganist Items in bag.
       @return Int amount of copies in bag.
    */
   int getFreqOf(const std::string&) const;

   /** Resizes the bag and copies over the items and recipts in bag.
       @param new_cap, Int to resize the bag to.
       @post if Successful the itemArr and recipts array are larger
             and contain all the same info from before.
    */
   void resize(int);

    /** Checks weather bag is empty.
        @return True if Empty False if at least on item is in it.
    */
   bool isEmpty() const;

   /** sets all variables and arrays back to their initalized state.
       @post all arrays are size of MAX and recipts is initlized to
       all false.
    */
   void clear();

   /** displays both itemArr and recipts array.
    */
   void display() const;

  private:
   static const int MAX = 10;

   /** Pointer to Array of type Item. */
   Item *itemArr;

   /** Pointer to array of type Bool. */
   bool *recipts;

   /** Current max amount of items allowed in array. */
   int cap;

   /** Removes Item from itemArr[Hash], set recipts[Hash] to false.
       @param Hash, int of Item to remove.
       @post if succesful item is removed and recipt set to false,
             itemArr[hash] set to NULL, recipts[Hash] = false.
       @return copy of item that was deleted from itemArr.
    */
   Item remove(const int);

   /** Finds first availble open hash then stores item there.
       @param Name, string to name Item obj.
       @post if succesful item obj is added to itemArr.
       @return returns the unique hash that item was stored at.
    */
   int addItem(const std::string&);

   /** Sets recipts[Hash] to true.
       @param Hash, int value to set to true.
       @post if succesful recipts[Hash] = true.
    */
   void addRecipt(const int&);
};

#endif
