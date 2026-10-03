class Solution {
public:
    bool solve(vector<int>&arr,int n,int target,vector<vector<int>>&dp){
        //base case
        if(n<0){
            return false;
        }
        if(target<0){
            return false;
        }

        if(target==0){
            return 1;
        }

        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        bool include=solve(arr,n-1,target-arr[n],dp);
        bool exclude=solve(arr,n-1,target,dp);

        dp[n][target]=include||exclude;
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int target=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            target+=nums[i];
        }
        //yaha hi galti karunga
        if(target&1)
            return false;
        target=target/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        bool ans=solve(nums,n-1,target,dp);
        return ans;
    }
};