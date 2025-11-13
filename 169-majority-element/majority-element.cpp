class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        int ans = 0;
        for (auto& pair : mpp) {
            if (pair.second > n / 2) {
                return pair.first;
            }
        }
        return -1;
    }
    
}

;