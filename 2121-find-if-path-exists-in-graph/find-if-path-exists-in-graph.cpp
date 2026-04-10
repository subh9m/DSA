class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)return true;
        vector<int>vis(n, -1);

        vector<vector<int>>adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        q.push(source);

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            vis[it] = 1;

            if(it == destination)return true;

            for(auto iter: adj[it]){
                if(vis[iter] != -1)continue;

                q.push(iter);
            }
        }
        return false;
    }
};