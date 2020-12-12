/**
 * Definition for singly-linked list.
 */
#include <algorithm>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* prevent for {1} 1 input*/
        if(n == 1 && head->next != nullptr) {
            ListNode *remove_node = findNthFromENd(head, 2);
            remove_node->next = nullptr;
            return head;
        }else if(head->next == nullptr) {
            return nullptr;
        }

        ListNode *remove_node = findNthFromENd(head, n);
        ListNode *next_node = remove_node->next;
        std::swap(next_node->val, remove_node->val);
        remove_node->next = next_node->next;
        return head;
    }
    ListNode *findNthFromENd(ListNode *head, int n) {
        ListNode *fast_ptr = head;
        ListNode *slow_ptr = head;

        for(int i = 0; i < n; ++i){
            fast_ptr = fast_ptr->next;
        }
        while(fast_ptr != nullptr) {
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
        return slow_ptr;
    }
};

int main(){

}
