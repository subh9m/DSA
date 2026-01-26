class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        int n = arr.size();
        if(n == 2){
            ans.push_back({arr[0], arr[1]});
            return ans;
        }
        
        sort(arr.begin(), arr.end());
        int minDiff = arr[n-1];
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] <= minDiff){
                minDiff = min(minDiff, arr[i] - arr[i-1]);
            }
        }

        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i-1] == minDiff){
                ans.push_back({arr[i-1], arr[i]});
            }
        }

        return ans;
    }
};