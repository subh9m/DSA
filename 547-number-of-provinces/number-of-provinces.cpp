class Solution {
public:
    void dfs(int node, vector<vector<int>>&components, vector<int>&visited) {
        if(!visited[node]) visited[node] = 1;

        for(auto it: components[node]){
            if(!visited[it]){
                visited[it] = 1;
                dfs(it, components, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        int provinces = 0;
        vector<vector<int>>components(V+1);
        
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(isConnected[i][j] == 1) {
                    components[i+1].push_back(j+1);
                    components[j+1].push_back(i+1);
                }
            }
        }

        vector<int>visited(V+1, 0);
        for(int i = 0; i < V; i++){
            if(!visited[i+1]){
                provinces++;
                dfs(i+1, components, visited);
            }
        }

        return provinces;
    }
};