class Solution {
public:
    bool dfs(int node,  vector<bool> &visited, vector<bool> &pathVisited,
                vector<int> &check, vector<vector<int>>& graph){
                    visited[node] = 1;
                    pathVisited[node] = 1;
                    check[node] = 0;

                    for(auto it : graph[node]){
                        if(!visited[it]){
                            if(dfs(it, visited, pathVisited, check, graph))
                               return true;
                        } else if(pathVisited[it]){
                            return true;
                        }
                    }
                    check[node] = 1;
                    pathVisited[node] = 0;
                    return false;
                }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        vector<int> check(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]) dfs(i, visited, pathVisited, check, graph);
        }

        vector<int> safeNodes;

        for(int i = 0; i < V; i++){
            if(check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};