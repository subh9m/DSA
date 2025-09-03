class Solution {
public:
    void bfs(int node, vector<vector<int>>& adjLs, vector<int>& vis,
             vector<int>& comp) {
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        comp.push_back(node);

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto nei : adjLs[i]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                    comp.push_back(nei);
                }
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int E = edges.size();
        vector<vector<int>> adjLs(n);

      
        for (int i = 0; i < E; i++) {
            adjLs[edges[i][0]].push_back(edges[i][1]);
            adjLs[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                bfs(i, adjLs, vis, comp);

                int k = comp.size();
                long long edgeCount = 0;
                for (int node : comp) {
                    edgeCount += adjLs[node].size();
                }
                edgeCount /= 2; 

                if (edgeCount == 1LL * k * (k - 1) / 2) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
