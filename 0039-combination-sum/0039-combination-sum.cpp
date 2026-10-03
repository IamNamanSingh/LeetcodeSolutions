class Solution {
public:

    void unique(int index ,vector<int>& candidates,vector<int>& pt, int target,vector<vector<int>>& ans,int n){
        if(target == 0){
            ans.push_back(pt);
            return;
        }

        if(index < 0 || target<0){
            return;
        }
        
        pt.push_back(candidates[index]);
        unique(index,candidates,pt,target - candidates[index],ans,n);
        pt.pop_back();
        unique(index-1,candidates,pt,target,ans,n); 
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> arr;
        unique(n-1,candidates,arr,target,ans,n);
        return ans;
    }
};