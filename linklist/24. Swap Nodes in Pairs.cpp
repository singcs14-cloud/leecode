/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)return head;

        ListNode* dummy =new ListNode(0);
        dummy->next = head;
        ListNode* pre =  dummy;

        while(pre->next && pre->next->next){
            ListNode* first = pre->next;
            ListNode* second = pre->next->next;

            first->next = second->next;
            second->next = first;
            pre->next = second;
            pre  = first;
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
