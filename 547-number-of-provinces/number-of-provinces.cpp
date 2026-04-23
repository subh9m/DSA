class Solution {
public:
    void bfs(int &i, vector<int>&visited, vector<vector<int>>&adj){
        visited[i] = 1;
        queue<int>q;
        q.push(i);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: adj[node]){
                if(!visited[it]){
                visited[it] = 1;
                q.push(it); 
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V, vector<int>(V));
        vector<int>visited(V, 0);

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int provinces = 0;

        for(int i = 0; i < V; i++){
                if(!visited[i]){
                    provinces++;
                    bfs(i,visited, adj);
                }
        }

        return provinces;

    }
};