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
    int getHeight(TreeNode* root){
        if(root==NULL)return 0;

        int leftone=getHeight(root->left);
        int rightone=getHeight(root->right);

        return max(leftone,rightone)+1;
    }
    bool isBalanced(TreeNode* root) {
        //Base case
        if(root==NULL){
            return true;
        }
        //function
        int leftHeight=getHeight(root->left);
        int rightHeight=getHeight(root->right);
        int diff=abs(leftHeight-rightHeight);

        bool ans=(diff<=1);

        //recursion
        bool leftAns=isBalanced(root->left);
        bool rightAns=isBalanced(root->right);

        if(ans&&leftAns&&rightAns){
            return true;
        }
        else{
            return false;
        }
    }
};