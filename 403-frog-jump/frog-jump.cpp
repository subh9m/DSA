class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>>dp;

        dp[stones[0]].insert(0);

        for(int pos: stones){
            for(int k: dp[pos]){
                for(int step: {k-1, k, k+1}){
                    if(step > 0){
                        int nextPos = pos + step;
                        if(stones.back() == nextPos) return true;
                        if(binary_search(stones.begin(), stones.end(), nextPos)){
                            dp[nextPos].insert(step);
                        }
                    } 
                }
            }
        }
        return false;
    }
};