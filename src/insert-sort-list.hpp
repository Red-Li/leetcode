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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *p = head;
        head = 0;

        while(p){
            ListNode *h = head, *pre = 0;
            while(h && h->val < p->val){
                pre = h;
                h = h->next;
            }
            
            ListNode *q = p->next;
            p->next = h;
            if(h == head)
                head = p;
            else
                pre->next = p;
            p = q;
        }

        return head;
    }
};
