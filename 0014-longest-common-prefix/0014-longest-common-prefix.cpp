class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            char c=strs[0][i];
            bool value=true;

            for(int j=0;j<strs.size();j++){
                if(c !=strs[j][i]){
                    value=false;
                    break;
                }
            }
            if(value==false){
                break;
            }
            else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};