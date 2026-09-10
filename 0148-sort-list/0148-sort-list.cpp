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
    ListNode *findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode();
        ListNode*ansHead=ans;
        ListNode*head1=list1;
        ListNode*head2=list2;
        if(head1==NULL&&head2==NULL)return NULL;
        if(head1==NULL)return head2;
        if(head2==NULL)return head1;
        while(head1!=NULL&&head2!=NULL){
            if(head1->val<=head2->val){
                ans->next=head1;
                ans=ans->next;
                head1=head1->next;              
            }
            else{
                ans->next=head2;
                ans=ans->next;
                head2=head2->next;       
            }
        }
        while(head1!=NULL){
            ans->next=head1;
            ans=ans->next;
            head1=head1->next;
        }
        while(head2!=NULL){
            ans->next=head2;
            ans=ans->next;
            head2=head2->next;
        }
        return ansHead->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        //break LL linkedlist into 2 halves
        ListNode* mid=findMid(head);
        ListNode* left=head;
        ListNode*right=mid->next;
        mid->next=NULL;
        //sort  RE
        left=sortList(left);
        right=sortList(right);

        //merge both left ans right ans
        ListNode* mergedLL=merge(left,right);
        return mergedLL; 
    }
};