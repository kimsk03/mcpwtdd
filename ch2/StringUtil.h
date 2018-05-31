#ifndef StringUtil_h
#define StringUtil_h

namespace stringutil {
  std::string zeroPad(const std::string& word, const size_t MaxCodeLength) {
      auto zerosNeeded = MaxCodeLength - word.length();
      return word + std::string(zerosNeeded, '0');
  }

  std::string upperFront(const std::string& string) {
    return std::string(1,
      std::toupper(static_cast<unsigned char>(string.front())));
  }

  std::string head(const std::string& word) {
    return word.substr(0,1);
  }

  std::string tail(const std::string& word) {
    return word.substr(1);
  }
}

#endif
