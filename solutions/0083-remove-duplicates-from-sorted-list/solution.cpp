class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == nullptr) return nullptr;
        
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val != curr->next->val) {
                curr = curr->next;
            } else {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
        }

        return head;
    }
};

