class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        //first window
        for(int i=0;i<k;i++){
            //chote element ko remove kardo
            while(!dq.empty()&&nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            //insering element so that we can checkout of window
            dq.push_back(i);
        }
        //store answer for first window
        ans.push_back(nums[dq.front()]);
        //remianing window ko process karn ahi 
        for(int i=k;i<nums.size();i++){
            //out of element ko remove kardia
            if(!dq.empty()&&i-dq.front()>=k){
                dq.pop_front();
            }
            while(!dq.empty()&&nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            //insering element so that we can checkout of window
            dq.push_back(i);

            //current window ka ans
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};