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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy; 

        while(current->next != nullptr){

          if(current->next->val == val){
            ListNode* node_to_delete = current->next;
            current->next = node_to_delete->next;
            delete node_to_delete;
          }

          else{
            current=current->next;
          }

        }

    return dummy->next;
    }
};
