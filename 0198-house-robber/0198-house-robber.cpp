class Solution {
public:
    int solve(vector<int>&arr,int n,vector<int>&dp){
        if(n<0)return 0;
        if(n==0)return arr[0];

        if(dp[n]!=-1){
            return dp[n];
        }
        int include=solve(arr,n-2,dp)+arr[n];
        int exclude=solve(arr,n-1,dp);

        dp[n]=max(include,exclude);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        vector<int>dp(n,-1);
        int ans=solve(nums,n-1,dp);
        return ans;
    }
};