/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    void insertattail(Node* &head,Node* &tail,int val){

      Node* newnode = new Node(val);

      if(head == NULL){
         head=newnode;
         tail=newnode;
         return;
      }

      else{
         tail->next=newnode;
         tail=newnode;
      }


    }

    Node* copyRandomList(Node* head) {

      if(head == NULL) {
        return head;
      }

      Node* clonehead=NULL;
      Node* clonetail=NULL;

      Node* temp=head;

      while(temp != NULL){
        insertattail(clonehead,clonetail,temp->val);
        temp=temp->next;
      }  
      
unordered_map<Node*, Node*> mp;

      Node *originalnode=head;
      Node *clonenode=clonehead;

      while(originalnode != NULL and clonenode != NULL){

         mp[originalnode]=clonenode;
         originalnode=originalnode->next;
         clonenode=clonenode->next;

      }

      originalnode=head;
      clonenode=clonehead;

      while(originalnode != NULL){
         clonenode-> random = mp[originalnode->random];
         originalnode=originalnode->next;
         clonenode=clonenode->next;
      }

return clonehead;

    }
};
