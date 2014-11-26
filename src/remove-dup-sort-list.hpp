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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *p, *q;
        q = p = head;

        while(p){
            while(q && q->val == p->val){
                ListNode *t = q;
                q = q->next;
                if(p != t)
                    delete t;
            }

            p->next = q;
            p = q;
        }

        return head;
    }
};
