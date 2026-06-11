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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for (auto list : lists) {
             if (list) {
                minHeap.push(list);
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (!minHeap.empty()) {

          ListNode* temp = minHeap.top();
            minHeap.pop();

            curr->next = temp;
            curr = curr->next;

            if (temp->next) {
               minHeap.push(temp->next);
            }
        }

        return dummy->next;
    }
};
