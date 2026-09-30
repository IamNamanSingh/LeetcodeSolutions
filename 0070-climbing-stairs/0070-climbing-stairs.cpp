class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=solve(n-1,dp)+solve(n-2,dp);
        return dp[n];
    }
    int solvebot(int n,vector<int>&dp){
        if(n==0){
            dp[0]=1;
        }
        if(n==1)dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[n]=solve(n-1,dp)+solve(n-2,dp);
        }
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int a=solvebot(n,dp);
        return a;
    }
};