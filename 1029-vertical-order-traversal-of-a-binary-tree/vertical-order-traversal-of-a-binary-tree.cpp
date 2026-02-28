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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;

        if(root == nullptr) return ans;

        queue<pair<TreeNode*, pair<int, int>>>q;
        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>>mpp;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mpp[x][y].push(node->val);

            if(node->left != nullptr){
                q.push({node->left, {x-1, y+1}});
            }

            if(node->right != nullptr){
                q.push({node->right, {x+1, y+1}});
            }
        }

        for(auto &q: mpp){
            vector<int>column;
            for(auto &p: q.second){
                while(!p.second.empty()){
                    column.push_back(p.second.top());
                    p.second.pop();
                }
            }
            ans.push_back(column);
        }

        return ans;
    }
};