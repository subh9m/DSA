class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>>mpp;

        int n = grid.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mpp[i].push_back(grid[j][i]);
            }
        }

        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < mpp.size(); j++) {
                if(mpp[j] == grid[i]) result++;
            }
        }

        return result;
    }
};