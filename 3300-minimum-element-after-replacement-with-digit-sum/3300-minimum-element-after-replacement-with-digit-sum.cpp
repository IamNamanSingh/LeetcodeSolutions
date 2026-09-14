class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int sum=0;
            while(a!=0){
                sum+=a%10;
                a=a/10;
            }
            nums[i]=sum;
            mini=min(mini,sum);
        }
        return mini;
    }
};