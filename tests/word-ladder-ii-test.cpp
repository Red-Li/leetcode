

#include <vector>
#include <queue>
#include <unordered_set>

#include <gtest/gtest.h>

using namespace std;

namespace word_ladder_ii{
#define NAMESPACE
#include "word-ladder-ii.hpp"
}


using namespace word_ladder_ii;

class WordLadderIITest : public testing::Test
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


TEST_F(WordLadderIITest, test)
{
    Solution sol;
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    vector<vector<string> > res = sol.findLadders("hit", "cog", dict);
    
    unordered_set<string> dict1;
    dict1.insert("a");
    dict1.insert("b");
    dict1.insert("c");

    vector<vector<string> > res1 = sol.findLadders("a", "c", dict1);
    

}
