class Solution {
private:
    void bfs(int node, vector<int>&visited, vector<vector<int>>&adj){
        visited[node] = 1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            for(auto it: adj[vertex]){
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(V, 0);

        int provinces = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                provinces++;
                bfs(i, visited, adj);
            }
        }
        return provinces;
    }
};