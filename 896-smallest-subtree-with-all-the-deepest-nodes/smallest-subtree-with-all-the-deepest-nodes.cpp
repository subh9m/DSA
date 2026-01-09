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
    unordered_map<int,int>mpp;
    int maxDepth = 0;

    void func(TreeNode* root, int depth){
        if(root == nullptr) return;

        maxDepth = max(maxDepth, depth);
        mpp[root->val] = depth;
        func(root->left, depth + 1);
        func(root->right, depth + 1);
    }

    TreeNode* LCA(TreeNode* root){
        if(root == nullptr || mpp[root->val] == maxDepth) return root;

        TreeNode* left = LCA(root->left);
        TreeNode* right = LCA(root->right);

        if(left && right) return root;

        return (left != nullptr)? left : right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        func(root, 0);

        return LCA(root);
    }
};