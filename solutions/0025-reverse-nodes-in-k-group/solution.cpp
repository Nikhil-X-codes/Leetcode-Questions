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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL)
            return NULL;
        int count = 0;

        ListNode* temp = head;

        while (count < k && temp) {
            temp = temp->next;
            count++;
        }

        if (count < k)
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        count = 0;

        while (count < k) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }

        if (curr) {
            head->next = reverseKGroup(curr, k);
        }

        return prev;
    }
};
