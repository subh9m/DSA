class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        list<int> l1(nums.begin(), nums.end());
        for(int i = 0; i < k; i++){
            l1.push_front(nums[n - i - 1]);
        }
        for(int i = 0; i < k; i++){
            l1.pop_back();
        }
        nums.assign(l1.begin(), l1.end());

    }
};