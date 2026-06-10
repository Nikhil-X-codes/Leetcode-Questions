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
    ListNode* conquer(ListNode* head1, ListNode* head2) {

        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;

        if (head1->val <= head2->val) {
            head1->next = conquer(head1->next, head2);
            return head1;
        }

        else {
            head2->next = conquer(head1, head2->next);
            return head2;
        }
    }

    ListNode* divide(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        return second;
    }

    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* half = divide(head);

        head = sortList(head);
        half = sortList(half);

        return conquer(head, half);
    }
};
