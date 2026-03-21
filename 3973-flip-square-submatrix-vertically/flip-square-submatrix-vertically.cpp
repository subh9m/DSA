class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int z = x + k - 1;
        for(int i = x; i < x + k; i++){
            if(i >= z) break;
            for(int j = y; j < y + k; j++){
                swap(grid[i][j], grid[z][j]);
            }
            z--;
        }
        return grid;
    }
};