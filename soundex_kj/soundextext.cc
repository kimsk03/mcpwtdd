#include "Soundex.h"
#include "gmock/gmock.h"

class SoundexEncoding : public testing::Test 
{
public:
   Soundex soundex;

};

TEST_F(SoundexEncoding, ZeroPadTesting)
{
   EXPECT_EQ(soundex.ZeroPad("A1"), "A100");

}
