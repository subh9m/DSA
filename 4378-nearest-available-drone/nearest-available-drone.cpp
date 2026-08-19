class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        vector<int>dist(n);

        for(int i = 0; i < n; i++){
            int distance = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if(distance <= drones[i][2]) dist[i] = distance;
            else dist[i] = -1;
        }

        int result = -1;
        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            if(dist[i] == ans) continue;
            if(dist[i] != -1 && dist[i] <= ans){
                ans = dist[i];
                result = i;
            }
        }
        return result;
    }
};