class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        for(int i = 1; i < n; i++){
            gain[i] += gain[i-1];
        }

        int result = *max_element(gain.begin(), gain.end());

        if(result < 0) return 0;
        return result;
    }
};