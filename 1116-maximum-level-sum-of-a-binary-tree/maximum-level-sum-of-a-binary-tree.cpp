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
        int maxSum = INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        int result;
        while(!q.empty()) {
            int size = q.size();
            int levelSum = 0;
            level++;

            for(int i = 0; i < size; i++) {
                auto it = q.front();
                q.pop();
                levelSum += it->val;

                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            if(levelSum > maxSum) {
                maxSum = max(maxSum, levelSum);
                result = level;
            }
        }

        return result;
    }
};