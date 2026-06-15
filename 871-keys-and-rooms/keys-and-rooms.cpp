class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&visited) {
        if(!visited[node]) visited[node] = true;

        for(auto it: adj[node]) {
            if(!visited[it]){
                visited[it] = true;
                dfs(it, adj, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<vector<int>>adj(n);
        vector<bool>visited(n, false);

        for(int i = 0; i < n; i++) {
            for(auto it: rooms[i]) {
                adj[i].push_back(it);
            }
        }

        int components = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                visited[i] = true;
                components++;
                dfs(i, adj, visited);
            }
        }

        return (components == 1);
    }
};