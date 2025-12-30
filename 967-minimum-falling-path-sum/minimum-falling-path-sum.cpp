class Solution {
public:
    const int INF = 1e9;
    int func(int i, int j, int c, vector<vector<int>>&matrix, vector<vector<int>>&dp){
        if(j >= c || j < 0) return INF;

        if(i == 0) return matrix[0][j];

        if(dp[i][j] != INF) return dp[i][j];

        int up = matrix[i][j] + func(i-1, j, c, matrix, dp);
        int leftDiagonal = matrix[i][j] + func(i-1, j-1, c, matrix, dp);
        int rightDiagonal = matrix[i][j] + func(i-1, j+1, c, matrix, dp);

        return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>>dp(r, vector<int>(c, INF));
        int mini = INT_MAX;

        for(int i = 0; i < c; i++){
            int curr = func(r - 1, i, c, matrix, dp);
            mini = min(curr, mini);
        }
        return mini;
    }
};