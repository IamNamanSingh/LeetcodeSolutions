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
    Node* helper(Node* head,unordered_map<Node*,Node*>&mp){
        if(head==NULL)return NULL;
        Node* newHead=new Node(head->val);
        mp[head]=newHead;
        newHead->next=helper(head->next,mp);
        if(head->random){
            newHead->random=mp[head->random];
        }
        return newHead;
    }
    Node* copyRandomList(Node* head) {
        //unordered_map<Node*,Node*>mp;
        //return helper(head,mp);for O(n)space complexity
        if(!head)return NULL;
        Node*it=head;
        while(it){
            Node*CloneNode=new Node(it->val);
            CloneNode->next=it->next;
            it->next=CloneNode;
            it=it->next->next;
        }
        it=head;
        while(it){
            Node* CloneNode=it->next;
            CloneNode->random=it->random?it->random->next:NULL;
            it=it->next->next;
        }
        //Step-3:Detch
        it=head;
        Node*CloneHead=it->next;
        while(it){
            Node* CloneNode=it->next;
            it->next=it->next->next;
            if(CloneNode->next){
                CloneNode->next=CloneNode->next->next;
            }
            it=it->next;
        } 
        return CloneHead;
    }
};