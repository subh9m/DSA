class Solution {
private:
    int solve(string &a, string &b, int m, int n, vector<vector<int>>&dp){
        //if any one of them becomes zero, return the other.
        if(m == 0) return n;
        if(n == 0) return m;
        if(dp[m][n] != -1) return dp[m][n];
        if(a[m-1] == b[n-1]) return dp[m][n] = solve(a, b, m-1, n-1, dp);
    
            int insert = 1 + solve(a, b, m, n-1, dp);
            int del = 1 + solve(a, b, m-1, n, dp);
            int replace = 1 + solve(a, b, m-1, n-1, dp);
    

        return dp[m][n] = min({insert, del, replace}); 
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        //recursion starting from backward indices.
        return solve(word1, word2, word1.size(), word2.size(), dp);
    }
};