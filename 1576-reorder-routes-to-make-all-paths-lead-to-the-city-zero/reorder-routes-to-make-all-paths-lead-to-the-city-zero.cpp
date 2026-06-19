class Solution {
public:
    int result = 0;

    void bfs(int node, vector<int>&visited, vector<vector<int>>&adj, 
    map<vector<int>, int> &mpp) {

        queue<int>q;
        q.push(node);
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            for(auto iter: adj[it]){
                if(!visited[iter]){
                    visited[iter] = 1;
                    if(mpp.find({it, iter}) != mpp.end()){
                        result++;
                    }
                    q.push(iter);
                }
                }
            }
        }

    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        map<vector<int>, int>mpp;

        for(auto connection: connections) {
            mpp[connection]++;
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        vector<int>visited(n, 0);
        for(int i = 0; i < n; i++) {
            if(!visited[i]){
                visited[i] = 1;
                bfs(i, visited, adj, mpp);
            }
        }

        return result;
        
    }
};