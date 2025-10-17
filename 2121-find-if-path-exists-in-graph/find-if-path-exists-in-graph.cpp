class Solution {
private:
vector<vector<int>> adjList;

void addNode(int u, int v, bool isDirected = false){
    adjList[u].push_back(v);
    if(!isDirected){
        adjList[v].push_back(u);
    }
}
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        adjList.resize(n);

        for(int i = 0; i < edges.size(); i++){
            addNode(edges[i][0], edges[i][1]);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int list = q.front();
            q.pop();

            for(int element : adjList[list]){
                if(!visited[element]){
                    if(element == destination) return true;
                    visited[element] = true;
                    q.push(element);
                }

                
            }
        }
        return false;
    }
};