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
    int maxVal(TreeNode* root){
        //base case
        if(root==NULL){
            return -1;
        }
        TreeNode* temp=root;
        while(temp->right){
            temp=temp->right;
        }
        return temp->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }

        if(root->val==key){
            if(!root->left&&!root->right){
                delete root;
                return NULL;
            }
            else if(root->left&&!root->right){
                TreeNode* child=root->left;
                delete root;
                return child;
            }
            else if(!root->left&&root->right){
                TreeNode* child=root->right;
                delete root;
                return child;
            }
            else{
                //dono exist karte hai
                int prece=maxVal(root->left);
                root->val=prece;
                root->left=deleteNode(root->left,prece);
                return root;
            }
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};