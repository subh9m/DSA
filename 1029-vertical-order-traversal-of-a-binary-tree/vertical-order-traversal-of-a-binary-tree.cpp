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

        if(root == nullptr) return result;

        map<int, map<int, priority_queue<int, vector<int>, greater<int>>>>nodesMap;

        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;

            nodesMap[x][y].push(node->val);

            if(node->left){
                q.push({node->left, {x-1, y+1}});
            }

            if(node->right){
                q.push({node->right, {x+1, y+1}});
            }
        }

        for(auto &it: nodesMap){
            vector<int>level;
            for(auto &iter: it.second){
                while(!iter.second.empty()){
                    level.push_back(iter.second.top());
                    iter.second.pop();
                }
            }
            result.push_back(level);
        }

        return result;
    }
};