class Node{
    public:
    char data;
    int count;

    Node(char val,int c){
        data=val;
        count=c;
    }
};
class compare{
    public:
    bool operator()(Node a,Node b){
        return a.count<b.count;
    }
};
class Solution {
public:
    string reorganizeString(string s) {
        //create mapping
        int freq[26]={0};
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            freq[ch-'a']++;
        }
        priority_queue<Node,vector<Node>,compare>maxHeap;

        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                Node temp(i+'a',freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans="";
        while(maxHeap.size()>1){
            Node first=maxHeap.top();
            maxHeap.pop();
            Node second=maxHeap.top();
            maxHeap.pop();

            ans+=first.data;
            ans+=second.data;

            first.count--;
            second.count--;

            if(first.count!=0){
                maxHeap.push(first);
            }
            if(second.count!=0){
                maxHeap.push(second);
            }
        }
        if(maxHeap.size()==1){
            Node temp=maxHeap.top();
            maxHeap.pop();
            if(temp.count==1){
                ans+=temp.data;
            }
            else{
                return "";
            }
        }
        return ans;
    }
};