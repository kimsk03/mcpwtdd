#include "soundex.h"
#include <iostream>
int main(int argc, char* argv[]) {
  if (argc < 2)
    return 0;
  Soundex soundex;
  std::cout << soundex.encode(argv[1]) << std::endl;
  return 0;
}

