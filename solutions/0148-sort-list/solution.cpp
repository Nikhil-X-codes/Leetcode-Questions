class Solution {
public:
    
    ListNode* conquoer(ListNode* first, ListNode* second){
        if(first == NULL) return second;
        if(second == NULL) return first;

        if(first->val <= second->val){
            first->next = conquoer(first->next, second);
            return first;
        } else {
            second->next = conquoer(first, second->next);
            return second;
        }
    }

    ListNode* divide(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        return second;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* half = divide(head);

        head = sortList(head);
        half = sortList(half);

        return conquoer(head, half);
    }
};
