class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int repeating = -1;
        int missing = -1;

        unordered_map<int, int>mpp;
        int n = grid.size();
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mpp[grid[i][j]]++;
            }
        }

        for(auto it: mpp){
            if(it.second == 2)repeating = it.first;
        }

        for(int i = 1; i <= n*n; i++){
            if(mpp.find(i) == mpp.end()){
                missing = i;
                break;
            }
        }

        return {repeating, missing};

    }
};