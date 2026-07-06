class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), [&](const auto &a, const auto &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            } else {
                return a[0] < b[0];
            }
        });

        vector<vector<int>>result;

        for(auto interval: intervals){
            if(result.empty()){
                result.push_back(interval);
            }
            else if(result.back()[0] <= interval[0] && result.back()[1] >= interval[1]){
                continue;
            } else result.push_back(interval);
        }

        return result.size();

    }
};