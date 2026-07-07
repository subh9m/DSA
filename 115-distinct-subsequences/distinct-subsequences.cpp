class Solution {
public:
     int func(string &s, string &t, int ind1, int ind2, vector<vector<int>>&dp){
        if(ind2 < 0) return 1;

        if(ind1 < 0) return 0;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int result = 0;

        if(s[ind1] == t[ind2]){
            int take = func(s, t, ind1-1, ind2-1, dp);
            int notTake = func(s, t, ind1-1, ind2, dp);

            result = (take + notTake);
        } else {
            result = func(s, t, ind1-1, ind2, dp);
        }

        return dp[ind1][ind2] = result;
     }
     int numDistinct(string s, string t) {
     int n = s.size();
     int m = t.size();

     vector<vector<int>>dp(n, vector<int>(m, -1));

     return func(s, t, n-1, m-1, dp);   
    }
};