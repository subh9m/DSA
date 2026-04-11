class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return -1;
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j+1; k < n; k++){
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        int curr = abs(i-j) + abs(j-k) + abs(k-i);
                        ans = min(ans, curr);
                    }
                }
            }
        }
        return (ans == 1e9)?-1:ans;
    }
};