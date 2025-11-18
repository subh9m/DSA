class Solution {
private:
int solve(int max, int min){
    if(min == 0){
        return max;
    } else{
        return solve(min, max % min);
    }
}
public:
    int findGCD(vector<int>& nums) {
        
        int max = *max_element(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());
        return solve(max, min);

    }
};