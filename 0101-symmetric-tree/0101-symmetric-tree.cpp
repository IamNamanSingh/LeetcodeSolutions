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
    bool isMirror(TreeNode* p,TreeNode* q){
        // Both are NULL
        if(p == NULL && q == NULL) {
            return true;
        }

        // One is NULL, other is not
        if(p == NULL || q == NULL) {
            return false;
        }

        // Values are different
        if(p->val != q->val) {
            return false;
        }

        // Values same → check both subtrees
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left,root->right);
    }
};