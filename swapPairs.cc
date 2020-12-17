#include <algorithm>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) {
            return nullptr;
        }
        if(head->next == nullptr) {
            return head;
        }
        ListNode *first_node = head, *second_node = head->next, *next_first = nullptr;
        head = second_node;
        next_first = second_node->next;
        second_node->next = first_node;
        first_node->next = swapPairs(next_first);
        return head;
    }
};
