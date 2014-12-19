/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;

        ListNode *p0 = head, *p1 = head->next;
        long i = 0;
        while(p1 && p0 != p1){
            p1 = p1->next;
            p0 = (i % 2) ? p0->next : p0;
            ++i;
        }

        return p0 == p1;
    }
};
