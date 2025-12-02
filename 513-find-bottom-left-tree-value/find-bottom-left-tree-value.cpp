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


 // THE NAIVE/BRUTE I CAN THINK RN IS BY USING THE LEFT VIEW, ILL FIND THE LEFT VIEW AND RETURN
 // THE LAST VALUE OF THE LEFT VIEW


class Solution {
private:
    void recursion(TreeNode* root, int level, vector<int>&ans){
        if(root == nullptr) return;
        if(ans.size() == level) ans.push_back(root->val);
        recursion(root->left, level+1, ans);
        recursion(root->right, level+1, ans);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<int>ans;
        recursion(root, 0, ans);
        int x = ans.size()-1;
        return ans[x];        
    }
};