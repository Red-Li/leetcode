/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return 0;

        ListNode *p0 = head, *p1 = head->next;
        long i = 0;
        while(p1 && p0 != p1){
            p1 = p1->next;
            p0 = (i % 2) ? p0->next : p0;
            ++i;
        }

        if(p0 == p1){
            p1 = p0->next;
            ListNode *h0 = head,
                     *h1 = p1,
                     *p = p1;
            p0->next = 0;

            while(h0 && p){
                h0 = h0->next;
                p = p->next;
            }
            
            if(h0){
                p = h0;
                h1 = head;
                h0 = p1;
            }
            else{
                h0 = head;
            }
            
            while(p){
                p = p->next;
                h1 = h1->next;
            }

            while(h1 != h0){
                h0 = h0->next;
                h1 = h1->next;
            }

            return h0;
        }
        else{
            return 0;
        }
    }
};
