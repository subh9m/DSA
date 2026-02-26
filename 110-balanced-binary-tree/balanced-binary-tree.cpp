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
    int height(TreeNode* root){
        if(!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        if(rh == -1 || lh == -1) return -1;
        if(abs(rh - lh) > 1) return -1;

        return 1 + max(rh, lh);
    }
    bool isBalanced(TreeNode* root) {
        int ans = height(root);
        if(ans == -1)return false;
        return true;
    }
};