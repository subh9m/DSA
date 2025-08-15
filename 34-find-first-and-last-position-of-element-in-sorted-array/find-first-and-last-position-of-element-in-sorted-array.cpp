class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        list<int> ans;
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        bool found = false;
        while (low <= high) {
            int mid = (high + low) / 2;
            if (nums[mid] == target) {
                found = true;
                ans.push_back(mid);
                int left = mid - 1;
                while (left >= 0 && nums[left] == target) {
                    ans.push_front(left);
                    left--;
                }

                int right = mid + 1;
                while (right < n && nums[right] == target) {
                    ans.push_back(right);
                    right++;
                }
                break;
            }

            else if (target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(found){
            vector<int> result;
            result.push_back(ans.front());
            result.push_back(ans.back());
            return result;
        }
        return {-1, -1};
    }
};