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
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode* temp = root;
        queue<TreeNode*>q;
        q.push(temp);

        vector<int>levelSum;
        while(!q.empty()){

            int size = q.size();
            int sum = 0;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            levelSum.push_back(sum);
        }

        int idx = max_element(levelSum.begin(), levelSum.end()) - levelSum.begin();
        return idx + 1;

    }
};