class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

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
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};