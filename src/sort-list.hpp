/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#ifndef NAMESPACE
#include <limits.h>
#endif

class Solution {

    ListNode *nextNNode(ListNode *cur, int n)
    {
        while(n-- && cur)
            cur = cur->next;
        return cur;
    }

    std::pair<ListNode*, ListNode*> mergeList(ListNode *h0, ListNode *h1, int n)
    {
        ListNode node(INT_MIN);
        ListNode *h = &node;
        int n0 = n, n1 = n;
        while(n0 && n1 && h0 && h1){
            if(h0->val < h1->val){
                h->next = h0;
				h = h0;
                h0 = h0->next;
                --n0;
            }
            else{
                h->next = h1;
				h = h1;
                h1 = h1->next;
                --n1;
            }
        }

        while(n0 && h0){
            h->next = h0;
			h = h0;
            h0 = h0->next;

            --n0;
        }

        while(n1 && h1){
            h->next = h1;
			h = h1;
            h1 = h1->next;

            --n1;
        }

        h->next = 0;

        return std::make_pair(node.next, node.next ? h : 0);
    };

    ListNode *sortList(ListNode *head, int n)
    {
        ListNode *h0 = head,
                 *h1 = nextNNode(h0, n),
                 *h2 = nextNNode(h1, n),
                 *h = 0;
        if(!h1) //list is in order
            return 0;

        while(h1){
            std::pair<ListNode*, ListNode*> rl = mergeList(h0, h1, n);
            if(h)
                h->next = rl.first;
            else
                head = h = rl.first;

            h = rl.second;

            h0 = h2;
            h1 = nextNNode(h0, n);
            h2 = nextNNode(h1, n);
        }

		if(h0)
			h->next = h0;

        return head;
    }

public:
    ListNode *sortList(ListNode *head) {

        for(int i = 1;; i *= 2){
            ListNode *h = sortList(head, i);
            if(!h)
                break;
            else
                head = h;
        }

        return head;
    }
};
