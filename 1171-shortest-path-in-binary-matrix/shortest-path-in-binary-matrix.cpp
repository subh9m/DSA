class Solution {
public:
    vector<int>delrow = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int>delcol = {0, 1, 1, 1, 0, -1, -1, -1};

    bool isValid(int &nrow, int &ncol, int &n){
        if(nrow < 0 || nrow >= n) return false;
        if(ncol < 0 || ncol >= n) return false;
        return true;

    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1 && grid[0][0] != 1) return 1;
        if(n == 1 && grid[0][0] == 1) return -1;


        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;

        vector<vector<int>>dist(n, vector<int>(n, 1e9));

        pair<int, int>source = {0, 0};
        dist[0][0]=1;

        queue<pair<int, pair<int, int>>>q;
        q.push({1, {0, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i = 0; i < 8; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(isValid(nrow, ncol, n) && 
                grid[nrow][ncol] == 0 &&
                1 + dis < dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + dis;

                    if(nrow == n-1 && 
                       ncol == n-1){
                        return dis+1;
                    }
                    q.push({dis + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};