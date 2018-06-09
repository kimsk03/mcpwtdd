#ifndef SOUNDEX_H_
#define SOUNDEX_H_
#include <string>

class Soundex
{
public:
   std::string ZeroPad(std::string word){
        auto length = 4 - word.size();
        if(length > 0) {
	  while(length > 0) {
             word += "0";
             length--;
          }
        }

        return word;
   }


};






#endif
