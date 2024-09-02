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
        
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while (head != NULL && head->next != NULL) {

            if (head->val != head->next->val) {
                prev = prev->next;
            }
             else {

                while (head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }

                prev->next = head->next;
            }

            head = head->next;
        }
        
        return dummy->next;
    }
};

