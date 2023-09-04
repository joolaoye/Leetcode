/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define bool int
#define true 1
#define false 0

// Floyd-Warshall Algorithm
bool hasCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast && fast->next){
        fast = fast->next->next;
        if (fast == slow) return true;

        slow = slow->next;
    }

    return false;
}