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

// Optimized Solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry;
        auto dummy = new ListNode();
        auto tail = dummy;

        while (l1 || l2 || carry){
            auto v1 = (l1) ? l1->val : 0;
            auto v2 = (l2) ? l2->val : 0;

            auto sum = v1 + v2 + carry;
            carry = sum / 10;
            
            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            l1 = (l1) ? l1->next : NULL;
            l2 = (l2) ? l2->next : NULL;
        }

        return dummy->next;
    }
};