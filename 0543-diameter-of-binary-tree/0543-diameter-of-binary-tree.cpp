/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int leftHeight=solve(root->left,ans);
        int rightHeight=solve(root->right,ans);
        int currHeight=max(leftHeight,rightHeight)+1;

        ans=max(ans,leftHeight+rightHeight);
        return currHeight;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};