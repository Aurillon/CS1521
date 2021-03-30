#ifndef Project1_H
#define Project1_H

class Seq {
public:

/** Default Constructor */
   Seq();

/** Add a Value of type double to the Object
    @Params Value to add to Object
    @Pre None
    @Post Value is added to the total.
*/
  void add(const double&);

/** Add Array of Values type double
    @Params arrValue array of values type double to add to object
    @Params arrSize Size of the array.
    @Pre None
    @Post if succesful all values are added to object
*/
  void add(double value[], int);

/** Add unknown amount of values to object
    @Pre None
    @Post If addidation succesful, all values added to object
*/
  void add();

/** Add a Value of type float to the Object
    @Params Value to add to Object
    @Pre None
    @Post Value is added to the total.
*/
  void add(const float&);

/** Returns the mean of object
    @Pre None
    @Post None
    @Return Mean return the (total/num of values added in object)
*/
  double Mean();

/** Returns value of length.
     @Pre None
     @Post None
     @Return Length return value stored in length
*/
  int Length();

/** Returns the last number in the Sequence
    @Return last num in sequence
 */
  double lastSeq();

/** Returns Sum of Sequence
 */
  double TotalValue();

/** Returns Smallest Value of Sequence
 */
  double Smallest();

/** Returns Largest Value of Sequence
 */
  double Largest();


/** Set Length to Value entered
    @Params Value (Int)
 */
  void setLength(const int&);

/** Sets Last to Value entered
    @Params Value (Double)
 */
  void setLast(const double&);

/** Sets Last to Value entered
    @Params Value (Double)
 */
  void setTotal(const double&);

/** Sets Small to Value entered
    @Params Value (Double)

 */
  void setSmall(const double&);

/** Sets Large to Value entered
    @Params Value (Double)

 */
  void setLarge(const double&);

/** Clears the Sequence Sets all variables
    back to zero */
  void clear();

/** calls all functions that return private data and display to user
    If length is <= 0 only calls funtions that are allowed to be run
    when length is <= 0
 */
  void display();

private:

/** Sets Length to one greater then before
    only to called by the base add Function
 */
  void setlength();

/** Smallest value entered into object */
  double small;

/** Largest Value entered into object*/
  double large;

/** Total of Values entered into object */
  double total;

/** Last Value entered into object */
  double last;

/** Length of the Sequence */
  int length;

};


#endif /** Project1_H */

