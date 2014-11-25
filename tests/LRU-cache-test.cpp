/**
 * @file LRU-cache-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-25
 */

#include <list>
#include <map>
#include <gtest/gtest.h>

namespace lru_cache{
#define NAMESPACE
#include "LRU-cache.hpp"
}
using namespace lru_cache;


class LRUCacheTest : public testing::Test
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


TEST_F(LRUCacheTest, test)
{
    LRUCache lc(3);
    
    lc.set(4, 4);
    lc.set(3, 3);
    lc.set(4, 4);
    lc.set(2, 2);
    lc.set(3, 3);

    EXPECT_EQ(lc.get(4), 4);
    EXPECT_EQ(lc.get(3), 3);
    EXPECT_EQ(lc.get(2), 2);

    lc.set(1, 1);

    EXPECT_EQ(lc.get(4), -1);
    EXPECT_EQ(lc.get(3), 3);
    EXPECT_EQ(lc.get(2), 2);
}
