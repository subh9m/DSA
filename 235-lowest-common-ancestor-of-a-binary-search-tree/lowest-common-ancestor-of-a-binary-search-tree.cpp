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

        int curr = root -> val;
        int a = p->val;
        int b = q->val;

        if(curr < a && curr < b){
            return lowestCommonAncestor(root->right, p, q);
        }

        if(curr > a && curr > b){
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};