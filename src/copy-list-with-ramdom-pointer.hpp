/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return head;
    
        //create node
        RandomListNode *p = head;
        while(p){
            RandomListNode *q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        
        //
        p = head;
        while(p){
            p->next->random = (p->random ? p->random->next : 0);
            p = p->next->next;
        }
        
        //
        p = head;
        head = 0;
        RandomListNode *cp = 0;
        while(p){
            RandomListNode *q = p->next;
            p->next = p->next->next;
            p = p->next;

            q->next = 0;
            if(head)
                cp->next = q;
            else
                head = q;
            cp = q;

        }

        return head;
    }
};
