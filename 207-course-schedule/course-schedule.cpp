class Solution {
private:
    vector<int> topoSort(int V, vector<int>adj[]){
        vector<int> InDegree(V, 0);

        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                InDegree[it]++;
            }
        }

        vector<int> ans;
        queue<int> q;

        for(int i = 0; i < V; i++){
            if(InDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(auto it: adj[node]){
                InDegree[it]--;

                if(InDegree[it] == 0) q.push(it);
            }
        }
        return ans;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<int> topo = topoSort(numCourses, adj);

        if(topo.size() < numCourses){
            return false;
        }

        return true;
    }
};