#include <string>
#include <map>

class Soundex {
 public:
  Soundex();
  ~Soundex();
  std::string Encode(std::string);
 private:
  const int MaxSizeOfString{4};
  std::string Encoding(std::string);
  std::string EncodeChar(char);
  std::string ZeroPad(std::string);
  std::string Head(std::string);
  std::string Tail(std::string);
  bool IsLessThanMaxSize(std::string);
  bool IsVowel(char);
};

Soundex::Soundex() {}
Soundex::~Soundex() {}

std::string Soundex::Encode(std::string message) {
  return Head(message) + Tail(ZeroPad(Encoding(message)));
}

std::string Soundex::Encoding(std::string message) {
  std::string encoded_string;
  for (int idx=0; idx<message.size(); idx++) {
    char m = message[idx];
//  for (const auto& m : message) {
    if (idx == 0 || !IsVowel(m)) {
      std::string encoded_char = EncodeChar(m);
      if (encoded_string.back() != encoded_char.back())
        encoded_string += encoded_char;
    }
  }
  return encoded_string;
}

std::string Soundex::EncodeChar(char character) {
  std::map<char, int> map { {'b',1}, {'f',1}, {'p',1}, {'v',1}, 
			    {'c',2}, {'g',2}, {'j',2}, {'k',2}, {'q',2}, {'s',2}, {'x',2}, {'z',2}, 
			    {'d',3}, {'t',3}, 
			    {'l',4}, 
			    {'m',5}, {'n',5}, 
			    {'r',6} 
			  };
  char key = static_cast<char>(std::tolower(character));
  if (map[key]) {
    return std::to_string(map[key]);
  }
  else {
    return std::string(1,character);
  }
}

std::string Soundex::ZeroPad(std::string message) {
  if (IsLessThanMaxSize(message)) {
    int size = MaxSizeOfString - message.size();
    std::string zero_pad;
    while(size--) {
      zero_pad += "0";
    }
    return message + zero_pad;
  }
  else
    return message.substr(0,3);
}

std::string Soundex::Head(std::string message) {
  return message.substr(0,1);
}

std::string Soundex::Tail(std::string message) {
  return message.substr(1);
}

bool Soundex::IsLessThanMaxSize(std::string message) {
  return message.size() < MaxSizeOfString;
}

bool Soundex::IsVowel(char character) {
  std::string vowels{"aeiouyhw"};
  return vowels.find(static_cast<char>(std::tolower(character))) != std::string::npos;
}
