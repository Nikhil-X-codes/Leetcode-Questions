/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
    unordered_set<ListNode *> visited;
    ListNode * current = head;

    while (current != NULL) {

        if (visited.find(current) != visited.end()) {
            return current;
        }

        visited.insert(current);
        current = current->next;
    }
      
      return NULL;
    }
};
