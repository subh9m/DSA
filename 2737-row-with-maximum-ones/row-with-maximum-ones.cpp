class Solution {
private:
    int lowerBound(vector<int> arr, int n, int x){
        int low = 0;
        int high = n -1;
        int ans = n;

        while(low <= high){
            int mid = (high + low) / 2;

            if(arr[mid] >= x){
                high = mid-1;
                ans = mid;
            } else{
                low = mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        for(int i = 0; i < rows; i++){
            sort(mat[i].begin(), mat[i].end());
        }

        int ans = 0;
        int maxZeroes = 0;

        for(int i = 0; i < rows; i++){
            int currZeroes = cols - lowerBound(mat[i], cols, 1);

            if(currZeroes > maxZeroes){
                maxZeroes = currZeroes;
                ans = i;
            }
        }
        return vector<int>{ans, maxZeroes};
    }
};