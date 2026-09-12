class Solution {
public:
vector<int> prevsmallerelement(vector<int>&input) {
    stack<int> s;
    s.push(-1);

    vector<int> ans1(input.size());
    // Left to right -> Previous Smaller
    for (int i = 0; i < input.size(); i++) {

        int curr = input[i];

        // Remove elements which are >= current
        while (s.top()!=-1 && input[s.top()] >= curr) {
            s.pop();
        }

        // Top is the previous smaller element
        ans1[i] = s.top();

        // Push current element
        s.push(i);
    }
    return ans1;
}
vector<int> nextsmallerelement(vector<int>&v) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(v.size());

    // Traverse from right to left
    for (int i = v.size() - 1; i >= 0; i--) {

        int curr = v[i];

        // Remove elements that are >= current
        while (s.top()!=-1 && v[s.top()] >= curr) {
            s.pop();
        }

        // Top is the next smaller element
        ans[i] = s.top();

        // Push current element for future elements
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int>& height) {
    //step1:-prevsmallerelement 
    vector<int>prev=prevsmallerelement(height);

    //step2:-nextsmallerelement
    vector<int>next=nextsmallerelement(height);

    int size=height.size();
    int maxArea=INT_MIN;

    for(int i=0;i<height.size();i++){
        int length=height[i];
        if(next[i]==-1){
            next[i]=size;
        }
        int width=next[i]-prev[i]-1;

        int area=length*width;
        maxArea=max(maxArea,area);
    }
    return maxArea;  
}
};