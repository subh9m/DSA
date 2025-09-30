class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        for(int i = 1; i < gain.size(); i++){
            gain[i] += gain[i-1];
        }
        int ans = *max_element(gain.begin(), gain.end());
        if(ans < 0) return 0;
        return ans;
    }
};