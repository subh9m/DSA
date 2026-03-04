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
    TreeNode* funcToMapParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent, int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res = new TreeNode(-1);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start)res = node;

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        return res;
    }

    int calculateTime(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent, TreeNode* target){
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<TreeNode*>visited;
        int maxi = 0;
        visited.insert(target);

        while(!q.empty()){

            int size = q.size();
            int fl = 0;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && visited.find(node->left) == visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                    fl = 1;
                }
                if(node->right && visited.find(node->right) == visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                    fl = 1;
                }

                if(parent.find(node) != parent.end() &&
                   visited.find(parent[node]) == visited.end()){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                    fl = 1;
                }  
            }
            if(fl)maxi++;
        }
        return maxi;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*>parent;
        TreeNode* target = funcToMapParent(root, parent, start);
        int mini = calculateTime(root, parent, target);
        return mini;
    }
};