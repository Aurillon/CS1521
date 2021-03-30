#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

#include "LinkedSet.h"


void displaySet(LinkedSet<std::string>& aset) {

   cout << "The set contains "
        << aset.getCurrentSize()
        << " items:"
        << endl;

   std::vector<std::string> setItems = aset.toVector();
   int numOfEntries = setItems.size();

   for(int i = 0; i < numOfEntries; ++i) {
      cout << setItems[i]
           << "\n";
   }

   cout << endl
        << endl;
}

void dictionarySet(LinkedSet<std::string>& dictionary, std::string& filename) {
   std::ifstream theFile(filename);
   std::string word;
   while(theFile) {
      theFile >> word;
      dictionary.add1(word);
   }
   theFile.close();
}

std::string wordCheck(std::string newWord) {
   int found;
   int length = newWord.length();
   std::string ascii = "!@#$%^&*()_-+={}[]:;\"\'`<>,.?/|\\";

   //cout << "checking: " << newWord << endl;

   found = newWord.find_first_of(ascii);
   while(found != std::string::npos) {
      if(found == 0) {
         newWord = newWord.substr(1, length);
         length = newWord.length();
         found = newWord.find_first_of(ascii);
      }
      else if((found + 1 < length) && ascii.find(newWord[found - 1])
              && ascii.find(newWord[found + 1])) {
         found = newWord.find_first_of(ascii, found + 1);
      }
      else {
         newWord.erase(found);
         length = newWord.length();
         found = newWord.find_first_of(ascii);
      }
   }
   for(int i = 0; i < length; i++) {
      newWord[i] = tolower(newWord[i]);
   }
   //cout << "Cleaned Word: " << newWord << endl;
   return newWord;
}

void CheckList(std::string& filename, LinkedSet<std::string>& ToCheckList) {
   std::ifstream myFile(filename);
   std::string word;
   while(myFile) {
      myFile >> word;
      word = wordCheck(word);
      ToCheckList.add(word);
   }
   myFile.close();
}

int main() {
   LinkedSet<std::string> toCheckList;
   LinkedSet<std::string> dictionary;
   LinkedSet<std::string> missSpelled;
   std::string filename;

   //cout << "Enter filename: small.dat\n";
   //cin >> filename;
   //dictionarySet(dictionary, filename);

   //cout << "Enter filename: small.txt\n";
   //cin >> filename;
   //filename = "small.txt";

   while(filename != "Quit") {
      cout << "Enter the file to use as your dictionary" << endl;
      cin >> filename;
      dictionarySet(dictionary, filename);

      cout << "Enter a Filename to check for spelling Errors" << endl;
      cin >> filename;
      CheckList(filename, toCheckList);

      missSpelled = dictionary.difference(toCheckList);

      cout << "Displaying words in the misspelled linkedSet" << endl;
      displaySet(missSpelled);

      toCheckList.clear();
      missSpelled.clear();
      cout << "Enter a Filename to check for spelling Errors or 'Quit'";
      cout << "to Exit" << endl;
      cin >> filename;
   }

   return 0;
}
