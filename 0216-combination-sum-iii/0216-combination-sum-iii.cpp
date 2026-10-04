class Solution {
public:
    void solve(int k,int target,int n,vector<int>&arr,vector<vector<int>>&ans){
        //base case
        if(k==0 && target==0){
            ans.push_back(arr);
            return;
        }
        if(k<0 || n>9 || target<0){
            return;
        }
        //function
        arr.push_back(n);
        //include fucntion
        solve(k-1,target-n,n+1,arr,ans);
        arr.pop_back();
        //exclude
        solve(k,target,n+1,arr,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(k,n,1,arr,ans);
        return ans;
    }
};