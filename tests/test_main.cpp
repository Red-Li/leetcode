/**
 * @file test_main.cpp
 * @brief  
 * @author Red Li
 * @version 
 * @date 2014-11-24
 */

#ifdef WIN32
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include <stdlib.h>

#include <iostream>
#include <gtest/gtest.h>


class unit_test : public testing::Environment
{
public:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};

int main(int argc, char *argv[])
{
#if defined(WIN32) && defined(_DEBUG)
    //start memory leak check now
    _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

    testing::AddGlobalTestEnvironment(new unit_test);
    testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();

    return ret;
}
