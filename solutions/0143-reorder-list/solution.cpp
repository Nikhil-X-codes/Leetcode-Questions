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
     
    ListNode* reversing(ListNode* head){

    if(head == NULL or head->next==NULL){
    return head;
  }

   ListNode *prev=NULL;
   ListNode *current=head;
   ListNode *forward=NULL;

  while (current != NULL)
  {
  forward=current->next;
  current->next=prev;
  prev=current;
  current=forward;
  }
  
  return prev;
  
    }


    void reorderList(ListNode* head) {
        
      ListNode* fast=head;
      ListNode* slow=head;

       while(fast and fast -> next != NULL){
        slow=slow->next;
        fast =fast->next->next;
       }

       ListNode *rev=reversing(slow);

       ListNode *curr=head;

       while(rev->next != NULL){

        ListNode * temp_rev=rev->next;
        ListNode * temp=curr->next;

        curr->next=rev;
        rev->next=temp;

        curr = temp;
        rev = temp_rev;
       }
        
    }
};
