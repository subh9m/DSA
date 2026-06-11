class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool>result(n, false);

        int maxi = INT_MIN;

        for(auto it: candies) maxi = max(maxi, it);


        for(int i = 0; i < n; i++) {
            if(candies[i] + extraCandies >= maxi) {
                result[i] = true;
            }
        } 

        return result;
    }
};