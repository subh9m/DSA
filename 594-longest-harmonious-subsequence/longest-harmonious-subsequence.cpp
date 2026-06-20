class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>freq;

        for(auto it: nums) freq[it]++;

        int maxLen = 0;

        for(auto it: freq){
            int num = it.first;

            if(freq.count(num+1)){
                maxLen = max(maxLen, freq[num] + freq[num+1]);
            }
        }
        return maxLen;   
    }
};