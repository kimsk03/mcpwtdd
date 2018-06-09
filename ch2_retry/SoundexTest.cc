#include "gmock/gmock.h"
#include "Soundex.h"

using ::testing::Eq;

class SoundexTest : public testing::Test {
 public:
  Soundex soundex;
};

TEST_F(SoundexTest, RetainsTheFirstLetter) {
  ASSERT_THAT(soundex.Encode("A000"), Eq("A000"));
}

TEST_F(SoundexTest, StopsWhenMoreThan4Character) {
  ASSERT_THAT(soundex.Encode("A0000"), Eq("A000"));
}

TEST_F(SoundexTest, ZeroPadIfLessThan4Character) {
  ASSERT_THAT(soundex.Encode("A"), Eq("A000"));
  ASSERT_THAT(soundex.Encode("A0"), Eq("A000"));
  ASSERT_THAT(soundex.Encode("A00"), Eq("A000"));
}

TEST_F(SoundexTest, DropsVowels) {
  ASSERT_THAT(soundex.Encode("Aaei"), Eq("A000"));
  ASSERT_THAT(soundex.Encode("Aouy"), Eq("A000"));
  ASSERT_THAT(soundex.Encode("Ahw"), Eq("A000"));
}

TEST_F(SoundexTest, ReplacesConsonantsWithAppropriateDigits) {
  ASSERT_THAT(soundex.Encode("Abcd"), Eq("A123"));
  ASSERT_THAT(soundex.Encode("Almr"), Eq("A456"));
}

TEST_F(SoundexTest, ReplaceCapitalConsonantsWithAppropriateDigits) {
  ASSERT_THAT(soundex.Encode("ABCD"), Eq("A123"));
}

TEST_F(SoundexTest, ReplacesTwoAdjacentNumbersToSingleNumber) {
  ASSERT_THAT(soundex.Encode("Abbc"), Eq("A120"));
  ASSERT_THAT(soundex.Encode("Abcc"), Eq("A120"));
}

TEST_F(SoundexTest, ReplacesTwoAdjacentNumbersSeparatedByHOrWToSingleNumber) {
  ASSERT_THAT(soundex.Encode("Abhb"), Eq("A100"));
  ASSERT_THAT(soundex.Encode("Acwc"), Eq("A200"));
}

TEST_F(SoundexTest, ApplyesReplacingTwoAdjacentNumbersToSingleNumberRuleToFirstLetter) {
  ASSERT_THAT(soundex.Encode("Bbcd"), Eq("B230"));
  ASSERT_THAT(soundex.Encode("Bhbc"), Eq("B200"));
}
