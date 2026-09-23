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
    bool solve(TreeNode* root,long long lb,long long ub){
        //base case
        if(root==NULL){
            return true;
        }
        if(root->val>lb &&root->val<ub){
            return solve(root->left,lb,root->val)&&solve(root->right,root->val,ub);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        bool ans=solve(root,-4294967296,4294967296);
        return ans;
    }
};