#include <stdio.h>

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
          return NULL;
        struct ListNode *ret, *tail;
        ret = head;
        tail = ret;
        head = head->next;
        tail->next = NULL;
        if(!head) {
            return ret;
        }
        while(head) {
            if(head->val != tail->val) {
                tail->next = head;
                tail = head;
                head = head->next;
                tail->next = NULL;
            }else{
                head = head->next;
            }
        }
        return ret;
    }
};

