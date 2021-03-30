#include <iostream>
#include <sstream>

#include "Cipher.cpp"


int main() {
   Cipher Rot;
   std::string plainText;

   std::cout << "===Test 1===" << std::endl;
   plainText = R"(Gur pvgl'f prageny pbzchgre gbyq lbh? E7Q7, lbh xabj
orggre guna gb gehfg n fgenatr pbzchgre! --P8CB)";

   std::cout << plainText << "\n" << std::endl;
   Rot = std::for_each(plainText.begin(), plainText.end(), Cipher());
   Rot.print();

   std::cout << "===End of Test 1===" << std::endl;


   std::cout << "\n===Test 2===" << std::endl;
   plainText = R"(Qrohttvat vf gjvpr nf uneq nf jevgvat gur pbqr va gur
svefg cynpr. Gurersber, vs lbh jevgr gur pbqr nf
pyrireyl nf cbffvoyr, lbh ner, ol qrsvavgvba, abg fzneg
rabhtu gbqroht vg. --Oevna Xreavtuna)";

   std::cout << plainText << "\n" << std::endl;
   Rot = std::for_each(plainText.begin(), plainText.end(), Cipher());
   Rot.print();

   std::cout << "===End of Test 2===" << std::endl;


   std::cout << "\n===Test 3===" << std::endl;
   plainText = R"(Jvgu 9 cnenzrgref V pna svg na ryrcunag, naq jvgu 0 V pna
znxr uvz jvttyr uvf gehax. --Wbua iba Arhznaa)";

   std::cout << plainText << "\n" << std::endl;
   Rot = std::for_each(plainText.begin(), plainText.end(), Cipher());
   Rot.print();

   std::cout << "===End of Test 3===" << std::endl;



   std::cout << "\n===User Input===" << std::endl;
   getline(std::cin, plainText);

   std::cout << plainText << "\n" << std::endl;
   Rot = std::for_each(plainText.begin(), plainText.end(), Cipher());
   Rot.print();

   return 0;
}
