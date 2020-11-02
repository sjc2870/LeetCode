
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        if(l1 == nullptr && l2 != nullptr)
            return l2;
        if(l1 != nullptr && l2 == nullptr)
            return l1;
        struct ListNode *ret = nullptr,*ret_tail = nullptr;
        if(l1->val < l2->val){
            ret = l1;
            ret_tail = l1;
            l1 = l1->next;
            ret_tail->next = nullptr;
        }else{
            ret = l2;
            ret_tail = l2;
            l2 = l2->next;
            ret_tail->next = nullptr;
        }
        while(l1 && l2 ){
            if((l1->val) < (l2->val)){
                    ret_tail->next = l1;
                    l1 = l1->next;
                    ret_tail = ret_tail->next;
                    ret_tail->next = nullptr;
            }else{
                    ret_tail->next = l2;
                    l2 = l2->next;
                    ret_tail = ret_tail->next;
                    ret_tail->next = nullptr;
            }
        }
        if(l1){
            l2 = l1;
        }
        ret_tail->next = l2;
        return ret;
    }
};
