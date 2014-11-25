/**
 * @file sort-list-test.cpp
 * @brief 
 * @author Red Li
 * @version 
 * @date 2014-11-25
 */


#include <gtest/gtest.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


#include <limits.h>
namespace sort_list{
#define NAMESPACE
#include "sort-list.hpp"
}


using namespace sort_list;

class SortListTest : public testing::Test
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


bool checkSortedList(ListNode *head, int size)
{
    int n = head ? 1 : 0;
    while(head && head->next){
        if(head->val > head->next->val)
            return false;
        head = head->next;
        ++n;
    }

    return n == size;
}

ListNode *createList(int *data, int size)
{
    ListNode *head = 0,
             *h = 0;
    for(int i = 0; i < size; ++i){
        ListNode *n = new ListNode(data[i]);
        if(h)
            h->next = n;
        else
            head = n;
        h = n;
    }

    return head;
}

void deleteList(ListNode *head)
{
    while(head){
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
    }
}


void checkList(int *data, int n)
{
    ListNode *head = createList(data, n);
    Solution sol;
    head = sol.sortList(head);

    EXPECT_TRUE(checkSortedList(head, n));
    deleteList(head);
}

TEST_F(SortListTest, test)
{
	int *l0 = 0,
        l1[] = {0},
        l2[] = {INT_MIN, 0},
        l3[] = {0, 0, 0, 2, 2},
        l4[] = {1, 2, 4, 3},
        l5[] = {9, 8, 7, 7, 6, 5, 4};
    
    checkList(l0, 0);
    checkList(l1, 1);
    checkList(l2, 2);
    checkList(l3, 5);
    checkList(l4, 4);
    checkList(l5, 7);
};



