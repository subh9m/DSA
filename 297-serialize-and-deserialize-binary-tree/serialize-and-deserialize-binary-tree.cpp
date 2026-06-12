/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        if(root == nullptr) return result;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
                auto it = q.front(); 
                q.pop();

                if(it == nullptr) {
                    result.append("#,");
                } else {
                    result.append(to_string(it->val) + ',');
                }

                if(it != nullptr) {
                    q.push(it->left);
                    q.push(it->right);
                }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            //left subtree
            getline(s, str, ',');
            if(str == "#"){
                it->left = nullptr;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                it->left = leftNode;
                q.push(leftNode);
            }

            //right subtree
            getline(s, str, ',');
            if(str == "#"){
                it->right = nullptr;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                it->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));