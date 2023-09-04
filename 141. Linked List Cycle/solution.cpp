#include <set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Hashset Solution
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> hashset;

        auto tail = head;

        while (tail){
            if (hashset.find(tail) != hashset.end()) return true;

            hashset.insert(tail);

            tail = tail->next;
        } 

        return false;
    }
};

// Floyd-Warshall Algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;

        while (fast && fast->next){
            fast = fast->next->next;
            if (fast == slow){
                return true;
            }
            slow = slow->next;
        }

        return false;   
    }
};