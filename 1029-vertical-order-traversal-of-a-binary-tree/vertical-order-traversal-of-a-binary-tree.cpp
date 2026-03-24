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
        vector<vector<int>>result;

        if(root == nullptr)return result;

        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>>mpp;
        queue<pair<TreeNode*, pair<int, int>>>q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            mpp[x][y].push(node->val);

            if(node->left){
                q.push({node->left, {x-1, y+1}});
            }
            if(node->right){
                q.push({node->right, {x+1, y+1}});
            }
        }

        for(auto &it: mpp){
            vector<int>column;
            for(auto &k: it.second){
                while(!k.second.empty()){
                    column.push_back(k.second.top());
                    k.second.pop();
                }
            }
            result.push_back(column);
        }
        return result;
    }
};