class Solution {
public:
    void solve(int index ,vector<int>& candidates,vector<int>&arr, int target,vector<vector<int>>& ans,int n){
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        if(index >=n || target<0){
            return;
        }
        for(int i=index;i<n;i++){
            if(i>index&& candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            arr.push_back(candidates[i]);
            solve(i+1,candidates,arr,target - candidates[i],ans,n);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> arr;
        solve(0,candidates,arr,target,ans,n);
        return ans;
    }
};