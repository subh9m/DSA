class Solution {
public:
    bool canCover(vector<int> &houses, vector<int> &heaters, int mid) {
        long long heater_pointer = 0;
        int n = houses.size();
        int m = heaters.size();
        for(int i = 0; i < n; i++) {
            long long house_pos = houses[i];
            while(heater_pointer < m && heaters[heater_pointer] < house_pos){
                heater_pointer++;
            }

            int dist_to_left_heater = INT_MAX;
            if(heater_pointer > 0){
                dist_to_left_heater = house_pos - heaters[heater_pointer - 1];
            }
            int dist_to_right_heater = INT_MAX;
            if(heater_pointer < m){
                dist_to_right_heater = heaters[heater_pointer] - house_pos;
            }
            int min_distance = min(dist_to_left_heater, dist_to_right_heater);
            if(min_distance > mid){
                return false;
            }
        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        long long low = 0;
        long long high = 1000000000;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(canCover(houses, heaters, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};