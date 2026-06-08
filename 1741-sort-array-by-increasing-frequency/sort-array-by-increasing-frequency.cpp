class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int>freq;

        for(auto it: nums) freq[it]++;

        sort(nums.begin(), nums.end(), [&](const auto &a, const auto &b){
            if(freq[a] == freq[b]){
                return a > b;
            } 
            return freq[a] < freq[b];
        });

        return nums;
    }
};