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
    void func(TreeNode* root, string &sub, vector<string>&ans){
        if(root == nullptr){
            return;
        }

        int oldLen = sub.size();

        string more = to_string(root->val);
        sub+=more;
        if(!root->left && !root->right){
            ans.push_back(sub);
        }
        
        else{
            sub += "->";
            func(root->left, sub, ans);
            func(root->right, sub, ans);
        }
        sub.resize(oldLen);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string sub = "";
        func(root, sub, ans);
        return ans;
    }
};