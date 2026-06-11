/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        int x = root->val;
        int y = p->val;
        int z = q->val;

        if(x < y && x < z){
            return lowestCommonAncestor(root->right, p, q);
        } 

        if(x > y && x > z) {
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;
    }
};