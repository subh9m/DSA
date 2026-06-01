class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result(numRows);

        int count = 1;

        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < count; j++){
                if(j == 0 || j == count-1){ 
                    result[i].push_back(1);
                    continue;
                }

                result[i].push_back((result[i-1][j] + result[i-1][j-1]));
            }
            count++;
        }

        return result;
    }
};