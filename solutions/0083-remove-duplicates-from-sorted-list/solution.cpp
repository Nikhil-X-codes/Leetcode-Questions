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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        ListNode* curr = head;

        while (curr != NULL && curr->next != NULL) { 

            if (curr->val != curr->next->val) {
                curr = curr->next; 
            } 
            
            else {
              
                ListNode* next_next = curr->next->next;
                ListNode* nodetodel = curr->next;
                delete nodetodel;
                curr->next = next_next;
            }
        }

        return head;
    }
};

