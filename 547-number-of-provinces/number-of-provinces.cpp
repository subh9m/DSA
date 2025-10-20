class Solution {
public:

    void bfs(int node, vector<vector<int>>&adjLs, vector<int>&visited) {
        visited[node] = 1;
        queue<int> q;
        q.push(node);

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            for(auto it: adjLs[i]) {
                if(!visited[it]){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjLs(V);

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> visited(V, 0);
        int cnt = 0;
        for(int i = 0; i < V; i++) {
            if(!visited[i]){
                cnt++;
                bfs(i, adjLs, visited);
            }
        }
        return cnt;
    }
};