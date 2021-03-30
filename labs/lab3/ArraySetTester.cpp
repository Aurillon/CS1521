/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2019
 *
 *  Testing the ArraySet class template.
 *
 *  Adapted from pages 103-104, 110-111 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 05 Feb 2019
 *
 *  @version 7.0 */

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

#include "ArraySet.h"

void displayBag(ArraySet<std::string> abag) {

   cout << "The bag contains "
        << abag.getCurrentSize()
        << " items:"
        << endl;

   std::vector<std::string> bagItems = abag.toVector();

   int numberOfEntries = (int)bagItems.size();

   for (int i(0); i < numberOfEntries; ++i) {
      cout << bagItems[i]
           << " ";
   }

   cout << endl
        << endl;
}

void bagTester(ArraySet<std::string>& bag, ArraySet<std::string> bag2) {

   cout << "isEmpty: returns "
        << bag.isEmpty()
        << "; should be 1 (true)"
        << endl;

   displayBag(bag);

   std::string items[] = {"one", "two", "three", "four", "five",
                          "one"};

   cout << "Add 6 items to the bag: "
        << endl;

   for (int i(0); i < 6; ++i) {
      bag.add(items[i]);
      bag2.add("Hello");
   }

   displayBag(bag);
   displayBag(bag2);

   cout << "bag.difference(bag2): "
        << "should return one, two, three, four, five" << endl;
   displayBag(bag.difference(bag2));


   cout << "bag2.difference(bag): "
        << "should return olny a single Hello" << endl;
   displayBag(bag2.difference(bag));

   cout << "isEmpty(): returns "
        << bag.isEmpty()
        << "; should be 0 (false)"
        << endl;

   cout << "getCurrentSize(): returns "
        << bag.getCurrentSize()
        << "; should be 6"
        << endl;

   cout << "Try to add another entry: add(\"extra\") returns "
        << bag.add("extra")
        << "; should be 0 (false)"
        << endl;

   cout << "contains(\"three\"): returns "
        << bag.contains("three")
        << "; should be 1 (true)"
        << endl;

   cout << "contains(\"ten\"): returns "
        << bag.contains("ten")
        << "; should be 0 (false)"
        << endl;

   cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one")
        << "; should be 2"
        << endl;

   cout << "remove(\"one\"): returns "
        << bag.remove("one")
        << "; should be 1 (true)"
        << endl;

   cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one")
        << "; should be 1"
        << endl;

   cout << "remove(\"one\"): returns "
        << bag.remove("one")
        << "; should be 1 (true)"
        << endl;

   cout << "remove(\"one\"): returns "
        << bag.remove("one")
        << "; should be 0 (false)"
        << endl;

   cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one")
        << "; should be 0"
        << endl;

   cout << endl;

   displayBag(bag);



   cout << "After clearing the bag, ";

   bag.clear();
   cout << "isEmpty(): returns "
        << bag.isEmpty()
        << "; should be 1 (true)"
        << endl;
}

int main() {

   ArraySet<std::string> bag;
   ArraySet<std::string> bag2;

   cout << "Testing the Array-Based Bag:"
        << endl
        << "The initial set is empty."
        << endl;

   bagTester(bag, bag2);

   cout << "All done!"
        << endl;

   return EXIT_SUCCESS;
}
