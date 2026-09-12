class Solution {
public:
    string decodeString(string s) {
        string ans="";
        stack<string>st;
        for(auto ch:s){
            if(ch==']'){
                string stringtorepeat="";
                while(!st.empty() && !isdigit(st.top()[0])){
                    string top=st.top();
                    stringtorepeat+=top=="["?"":top;
                    st.pop();
                }
                string numericTimes="";
                while(!st.empty()&& isdigit(st.top()[0])){
                    numericTimes+=st.top();
                    st.pop();
                }
                reverse(numericTimes.begin(),numericTimes.end());
                int n=stoi(numericTimes);

                //final decoding
                string currentdecode="";
                while(n--){
                    currentdecode+=stringtorepeat;
                }
                st.push(currentdecode);

            }
            else {
                string temp(1,ch);
                st.push(temp);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};