class Solution {
public:
    void bfs(int node, vector<int>&visited, vector<vector<int>>&adjL){
        visited[node] = 1;

        for(auto it: adjL[node]){
            if(!visited[it]){
                bfs(it, visited, adjL);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<vector<int>>adjL(V+1);
        vector<int>visited(V+1, 0);
        for(int i = 0; i <  V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j]){
                    adjL[i+1].push_back(j+1);
                    adjL[j+1].push_back(i+1);
                }
            }
        }

        int provinces = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i+1]){
                provinces++;
                bfs(i+1, visited, adjL);                
            }
        }
        return provinces;
    }
};