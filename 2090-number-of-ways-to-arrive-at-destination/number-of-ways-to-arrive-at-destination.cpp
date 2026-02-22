
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<pair<int,int>>adj[n];

        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long>mintime(n, LLONG_MAX);
        vector<long long>ways(n, 0);

        mintime[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long, int>>>pq;

        pq.push({0, 0});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            long long time = it.first;
            int node = it.second;

            for(auto iter: adj[node]){
                long long timeTaken = iter.second;
                int adjNode = iter.first;

                if(time + timeTaken < mintime[adjNode]){
                    mintime[adjNode] = time + timeTaken;
                    ways[adjNode] = ways[node];
                    pq.push({mintime[adjNode], adjNode});
                }

                else if(mintime[adjNode] == time + timeTaken){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }

        }

        return ways[n-1] % mod;

    }
};