class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEle = *max_element(nums.begin(), nums.end()) + k;
        vector<int> freq(maxEle + 1, 0);
        
        for(int &num: nums){
            freq[num]++;
        }

        for(int i = 1; i <= maxEle; i++) {
            freq[i] += freq[i-1];
        }

        int result = 0;
        for(int target = 0; target <= maxEle; target++){
            if(freq[target] == 0) continue;

            int leftnum = max(0, target - k);
            int rightnum = min(maxEle, target + k);

            int totalCount = freq[rightnum] - (leftnum > 0 ?freq[leftnum - 1] : 0);
            int targetCount = freq[target] - (target > 0? freq[target - 1]: 0);
            int needConversion = totalCount - targetCount;
            int maxPossibleFreq = targetCount + min(needConversion, numOperations);
            result = max(result, maxPossibleFreq);
        }
        return result;
    }
};