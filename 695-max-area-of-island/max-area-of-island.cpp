class Solution {
public:
    vector<int>delrow = {-1, 0, 1, 0};
    vector<int>delcol = {0, 1, 0, -1};

    bool isValid(int &row, int &col, int &n, int &m){
        if(row < 0 || row >= n) return false;
        if(col < 0 || col >= m) return false;
        return true;
    }

    void bfs(int row, int col, int &currArea, vector<vector<int>>&visited, vector<vector<int>>&grid){
        visited[row][col] = 1;
        currArea++;

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>>q;

        q.push({row, col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(isValid(nrow, ncol, n, m) && 
                !visited[nrow][ncol] && 
                grid[nrow][ncol] == 1){
                    visited[nrow][ncol] = 1;
                    currArea++;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>>visited(r, vector<int>(c, 0));

        int maxArea = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int currArea = 0;
                    bfs(i, j, currArea, visited, grid);
                    maxArea = max(maxArea, currArea);
                }
            }
        }

        return maxArea;
    }
};