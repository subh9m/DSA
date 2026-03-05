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
    bool func(TreeNode* root, int k, unordered_set<int>&st){
        if(root == nullptr)return false;

        int complement = k - root->val;

        if(st.count(complement)) return true;
        st.insert(root->val);

        return func(root->left, k, st) || func(root->right, k, st);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>st;
        return func(root, k, st);
    }
};