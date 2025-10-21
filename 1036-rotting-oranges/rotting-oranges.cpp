class Solution {
private:
    vector<int>delrow = {-1, 0, 1, 0};
    vector<int>delcol = {0, 1, 0, -1};

    bool isValid(int &nrow, int &ncol, int n, int m){
        if(nrow < 0 || nrow >= n) return false;
        if(ncol < 0 || ncol >= m) return false;
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair <pair<int, int>, int>>q;

        int freshOranges = 0;
        int rottenOranges = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2){
                    visited[i][j] = 2;
                    q.push({{i, j}, 0});
                } else if(grid[i][j] == 1) freshOranges++;
            }
        }

        int time = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i]; 

                if(isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1 
                    && visited[nrow][ncol] != 2) {
                        visited[nrow][ncol] = 2;
                        rottenOranges++;
                        q.push({{nrow, ncol}, t + 1});
                    }
            }
        }

        if(freshOranges == 0) return 0;
        if(rottenOranges != freshOranges) return -1;
        return time;
    }
};