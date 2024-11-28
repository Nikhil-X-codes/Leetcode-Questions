class Solution {
public:

    void solve(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = curr1->next;
        ListNode* curr3 = list2;

        while (curr3 != nullptr) {
            if (curr2 == nullptr) {
                curr1->next = curr3;
                return;
            }

            if (curr1->val <= curr3->val && curr3->val <= curr2->val) {
                ListNode* curr4 = curr3->next;
                curr1->next = curr3;
                curr3->next = curr2;
                curr1 = curr3;
                curr3 = curr4;
            } else {
                curr1 = curr2;
                curr2 = curr2->next;
            }
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val <= list2->val) {
            solve(list1, list2);
            return list1;
        } else {
            solve(list2, list1);
            return list2;
        }
    }
};

