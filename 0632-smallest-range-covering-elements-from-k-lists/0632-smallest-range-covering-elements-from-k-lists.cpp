class Node{
    public:
    int data;
    int row;
    int col;

    Node(int data,int r,int c){
        this->data=data;
        row=r;
        col=c;
    }
};
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int k=nums.size();
        priority_queue<Node*,vector<Node*>,compare>minHeap;

        for(int i=0;i<k;i++){
            int element=nums[i][0];
            maxi=max(maxi,element);
            mini=min(mini,element);
            minHeap.push(new Node(element,i,0));
        }

        int ansStart=mini;
        int ansEnd=maxi;
        while(!minHeap.empty()){
            Node* top=minHeap.top();
            int topelement=top->data;
            int topRow=top->row;
            int topCol=top->col;

            minHeap.pop();

            mini=topelement;

            //check for answer
            if(maxi-mini<ansEnd-ansStart){
                ansStart=mini;
                ansEnd=maxi;
            }

            //check for new element
            if(topCol+1<nums[topRow].size()){
                maxi=max(maxi,nums[topRow][topCol+1]);
                Node* newNode=new Node(nums[topRow][topCol+1],topRow,topCol+1);
                minHeap.push(newNode);
            }
            else{
                //there is no element
                break;
            }
        }
        vector<int>ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};