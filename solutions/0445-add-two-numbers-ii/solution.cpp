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
    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;

        while (curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
 
        l1 = reverse(l1);
        l2 = reverse(l2);

        if(l1->val == 0 && l2->val == 0) return new ListNode(0);

        ListNode* dummy = new ListNode(-1);
        int carry = 0;
        ListNode* curr = dummy;

        while (l1 || l2 || carry != 0) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        ListNode* res = reverse(dummy->next);

        while (res && res->val== 0) {
            ListNode* temp = res;
            res = res->next;
            delete temp;
        }

        return res;
    }
};
