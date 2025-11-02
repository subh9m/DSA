class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for(auto &g : guards) grid[g[0]][g[1]] = 2;
        for(auto &w : walls) grid[w[0]][w[1]] = 3;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(auto &g : guards){
            int row = g[0];
            int col = g[1];

            for(int i = 0; i < 4; i++){
                int newRow = row + delrow[i];
                int newCol = col + delcol[i];

                while(newRow >= 0 && newRow < m &&
                      newCol >= 0 && newCol < n &&
                      grid[newRow][newCol] != 3 &&
                      grid[newRow][newCol] != 2){
                        if(grid[newRow][newCol] == 0){
                            grid[newRow][newCol] = 1;
                        }
                        newRow += delrow[i];
                        newCol += delcol[i];
                      }

            }

        }

        int count = 0;
         for(auto &row : grid){
            for(auto cell: row){
                if(cell == 0) count++;
            }
         }

         return count;
    }
};