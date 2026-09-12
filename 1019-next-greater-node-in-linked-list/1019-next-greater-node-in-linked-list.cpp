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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=curr;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int>s;
        s.push(0);
        int i=0;
        ListNode*temp=head;
        while(temp){
            i++;
            temp=temp->next;
        }
        vector<int>ans(i);
        head=reverse(head);
        i-=1;
        if(head==NULL || head->next==NULL)return ans;
        while(head){
            while(!s.empty() && s.top()<=head->val){
                s.pop();
            }
            if(s.empty())ans[i]=0;
            else ans[i]=s.top();
            i--;
            s.push(head->val);
            head=head->next;
        }
        return ans;
    }
};