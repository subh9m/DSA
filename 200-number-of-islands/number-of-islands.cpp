class Solution {
private: 
vector<int>delrow = {-1, 0, 1, 0};
vector<int>delcol = {0, 1, 0, -1};

bool check(int &nrow, int &ncol, int &n, int &m){
    if(nrow < 0 || nrow >= n) return false;
    if(ncol < 0 || ncol >= m) return false;
    return true;
}
    void bfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int, int>>q;
        q.push({row, col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(check(nrow, ncol, n, m) 
                  && grid[nrow][ncol] == '1' && 
                  !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int i = grid.size();
        int j = grid[0].size();

        vector<vector<int>>visited(i, vector<int>(j, 0));

        int islands = 0;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                if(grid[row][col] == '1' && !visited[row][col]){
                    islands++;
                    bfs(row, col, visited, grid);
                }
            }
        }

        return islands;

    }
};