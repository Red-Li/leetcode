/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int size(ListNode *h)
    {
        int i = 0;
        while(h){
            ++i;
            h = h->next;
        }

        return i;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return 0;

        int la = size(headA),
            lb = size(headB);
        ListNode *ha = (la >= lb) ? headA : headB,
                 *hb = (la < lb) ? headA : headB;
        int diff = abs(la - lb);
        while(diff--)
            ha = ha->next;
        
        int l = min(la, lb);
        while(l--){
            if(ha == hb)
                return ha;
            ha = ha->next;
            hb = hb->next;
        }
        
        return 0;
    }
};
