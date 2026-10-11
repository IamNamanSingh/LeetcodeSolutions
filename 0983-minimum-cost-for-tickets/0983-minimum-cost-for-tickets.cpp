class Solution {
public:
    int solve(int n,vector<int>&days,vector<int>&cost,int index,vector<int>&dp){
        if(index>=n){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }
        //1 day pass
        int option1=cost[0]+solve(n,days,cost,index+1,dp);

        //7 days pass
        int i=index;
        while(i<n&& days[i]<days[index]+7){
            i++;
        }
        int option2=cost[1]+solve(n,days,cost,i,dp);

        //30 days pass
        i=index;
        while(i<n&& days[i]<days[index]+30){
            i++;
        }
        int option3=cost[2]+solve(n,days,cost,i,dp);

        dp[index]=min(option1,min(option2,option3));
        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+2,-1);
        return solve(days.size(),days,costs,0,dp);
    }
};