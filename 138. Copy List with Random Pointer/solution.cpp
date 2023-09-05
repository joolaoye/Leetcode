#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Hashmap Solution
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hashmap;

        auto dummy = new Node(0);
        auto tail = dummy;

        auto temp = head;

        while (temp){
            tail->next = new Node(temp->val);
            hashmap[temp] = tail->next;
            temp = temp->next;
            tail = tail->next;
        }

        tail = dummy->next;

        while (head){
            if (head->random) tail->random = hashmap[head->random];
            head = head->next;
            tail = tail->next;
        }

        return dummy->next;
    }
};

// Optimized Hashmap Solution
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hashmap;

        auto dummy = new Node(0);
        auto tail = dummy;

        auto temp = head;

        while (temp){
            if (hashmap.find(temp) == hashmap.end()) hashmap[temp] = new Node(temp->val);
            if (temp->random && hashmap.find(temp->random) == hashmap.end()) hashmap[temp->random] = new Node(temp->random->val);

            tail->next = hashmap[temp];
            if (temp->random) tail->next->random = hashmap[temp->random];

            temp= temp->next;
            tail = tail->next; 
        }

        return dummy->next;
    }
};