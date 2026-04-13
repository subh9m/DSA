class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxi = -1;

        int n = arr.size();
        for(int i = n-1; i >= 0; i--){
            if(i == n-1){
                maxi = arr[i];
                arr[i] = -1;
                continue;
            }
            int temp = arr[i];
            arr[i] = maxi;
            maxi = max(maxi, temp);
        }
        return arr;
    }
};