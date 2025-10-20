class Solution {
private:
vector<int> delrow = {-1, 0, 1, 0};
vector<int> delcol = {0, 1, 0, -1};

    bool isValid(int &nrow, int &ncol, int &n, int &m){
    if(nrow < 0  || nrow >= n) return false;
    if(ncol < 0 || ncol >= m) return false;
    return true;

}
public:

    void bfs(queue<pair<int, int>>&q, vector<vector<bool>>&vis, 
             vector<vector<int>>&grid) {
                int n = grid.size();
                int m = grid[0].size();

                while(!q.empty()){
                    auto cell = q.front();
                    q.pop();

                    int row = cell.first;
                    int col = cell.second;
                    for(int i = 0; i < 4; i++) {
                        int nrow = row + delrow[i];
                        int ncol = col + delcol[i];

                        if(isValid(nrow, ncol, n, m) &&
                           grid[nrow][ncol] && !vis[nrow][ncol]){
                            vis[nrow][ncol] = true;
                            q.push({nrow, ncol});
                           }
                    }
                }
             }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m, false));

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 ||i == n - 1 
                   || j == 0 || j == m -1) &&
                    grid[i][j] == 1) {
                        vis[i][j] = true;
                        q.push({i, j});
                    }
            }
        }

        bfs(q, vis, grid);

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};