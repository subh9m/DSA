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
    void inorder(TreeNode* root, vector<int>&result) {
        if(root == nullptr) return;

        inorder(root->left, result);
        if(!root->left && !root->right){
            result.push_back(root->val);
        }
        inorder(root->right, result);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>tree1;
        vector<int>tree2;

        inorder(root1, tree1);
        inorder(root2, tree2);

        return (tree1 == tree2);
    }
};