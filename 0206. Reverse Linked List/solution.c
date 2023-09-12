/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL){
        return NULL;
    }

    struct ListNode* prev = NULL;
    struct ListNode* tmp;

    while (head != NULL){
        tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }

    return prev;
}