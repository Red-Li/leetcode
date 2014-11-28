
#include <vector>
#include <queue>
#include <unordered_set>

#include <gtest/gtest.h>

using namespace std;

namespace word_ladder{
#define NAMESPACE
#include "word-ladder.hpp"
}


using namespace word_ladder;

class WordLadderTest : public testing::Test
{
public:
    static void SetUpTestCase()
    {
        
    }
    static void TearDownTestCase()
    {
    }

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};


TEST_F(WordLadderTest, test)
{
    Solution sol;

    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("cog");
    dict.insert("dog");
    dict.insert("tot");
    dict.insert("hog");
    dict.insert("hop");
    dict.insert("pot");
    dict.insert("dot");

    EXPECT_EQ(sol.ladderLength("hot", "dog", dict), 3);

}
