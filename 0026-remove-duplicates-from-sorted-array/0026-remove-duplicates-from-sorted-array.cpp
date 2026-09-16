class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        stack<int>s;
        int j=0;
        s.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=s.top()){
                s.push(nums[i]);
            }
            else{
                j++;
            }
        }
        while(j>0){
            nums.pop_back();
            j--;
        }
        int k=0;
        while(!s.empty()){
            nums[k++]=s.top();
            s.pop();
        }
        sort(nums.begin(),nums.end());
        return nums.size();
    }
};