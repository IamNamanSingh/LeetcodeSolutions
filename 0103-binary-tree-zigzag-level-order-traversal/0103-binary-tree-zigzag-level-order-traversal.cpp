class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> arr;

        if(root == NULL) return ans;

        bool lefttoright = true;

        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(temp != NULL) {
                arr.push_back(temp->val);

                if(temp->left) {
                    q.push(temp->left);
                }

                if(temp->right) {
                    q.push(temp->right);
                }
            }
            else {
                // current level is complete

                if(!lefttoright) {
                    reverse(arr.begin(), arr.end());
                }

                ans.push_back(arr);
                arr.clear();

                // change direction for next level
                lefttoright = !lefttoright;

                if(!q.empty()) {
                    q.push(NULL);
                }
            }
        }

        return ans;
    }
};