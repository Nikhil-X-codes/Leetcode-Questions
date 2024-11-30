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

    bool validpalidrome(vector<int>arr){
      
      int n=arr.size();
      int st=0;
      int end=n-1;

      while(st <= end){

        if(arr[st] != arr[end]){
          return false;
        }

        st++;
        end--;
      }

      return true;
    }

    bool isPalindrome(ListNode* head) {
        
        if(head ->next == nullptr) return true;


        vector<int>arr;
        ListNode* temp=head;

        while(temp != nullptr){
          arr.push_back(temp->val);
          temp=temp->next;
        }

        return validpalidrome(arr);
    }
};
