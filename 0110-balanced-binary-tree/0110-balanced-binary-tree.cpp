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
    int getHeight(TreeNode* root,bool &isbalanced){
        if(root==NULL){
            return 0;
        }
        int leftHeight=getHeight(root->left,isbalanced);
        int rightHeight=getHeight(root->right,isbalanced);

        //check for correct node is it balanced
        if(isbalanced&& abs(leftHeight-rightHeight)>1){
            isbalanced=false;
            return 0;
        }
        return max(leftHeight,rightHeight)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool isbalanced=true;
        getHeight(root,isbalanced);
        return isbalanced;
    }
};