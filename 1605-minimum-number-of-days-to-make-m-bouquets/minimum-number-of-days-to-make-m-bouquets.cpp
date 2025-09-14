class Solution {
public:
    bool bouquetPossible(vector<int> &bloomDay, int m, int k, int mid){
        int n = bloomDay.size();
        int count = 0;
        int bloom = 0;
        for(int i = 0; i < n; i++) {
            if(bloomDay[i] <= mid){
                count++;
            }
            else{
                bloom += count / k;
                count = 0;
            }
        }
        bloom += count / k;
        if(bloom >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long x = (long long)m*k;
        if(x > n) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(bouquetPossible(bloomDay, m, k, mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};