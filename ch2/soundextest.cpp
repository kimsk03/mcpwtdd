#include "soundex.h"
#include "gmock/gmock.h"
using ::testing::Eq;

class SoundexEncoding: public testing::Test {
public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
  ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
  EXPECT_THAT(soundex.encode("Ab"), Eq("A100"));
  EXPECT_THAT(soundex.encode("Ac"), Eq("A200"));
  EXPECT_THAT(soundex.encode("Ad"), Eq("A300"));
  EXPECT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits) {
  EXPECT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

