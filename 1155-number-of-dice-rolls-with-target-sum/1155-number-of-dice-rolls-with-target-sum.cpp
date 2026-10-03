class Solution {
public:
    long long MOD = 1000000007;

    int solve(int n, int k, int target,
              vector<vector<long long>>& dp) {

        // Base cases
        if(n == 0 && target == 0) {
            return 1;
        }

        if(n == 0 && target != 0) {
            return 0;
        }

        if(n != 0 && target == 0) {
            return 0;
        }

        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        long long ans = 0;

        // Current die can show 1 to k
        for(int i = 1; i <= k; i++) {
            if(target - i >= 0) {
                ans = (ans + solve(n - 1, k,target - i, dp)) % MOD;
            }
        }
        dp[n][target] = ans;
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {

        vector<vector<long long>> dp(n + 1,vector<long long>(target + 1, -1));

        return solve(n, k, target, dp);
    }
};