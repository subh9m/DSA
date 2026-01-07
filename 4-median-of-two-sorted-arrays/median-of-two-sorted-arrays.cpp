class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int>merged;
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                merged.push_back(nums1[i++]);
            } else{
                merged.push_back(nums2[j++]);
            }
        }

        while(i < n) merged.push_back(nums1[i++]);
        while(j < m) merged.push_back(nums2[j++]);

        int merged_size = merged.size();

        if(merged_size % 2 != 0){
            int mid = merged_size / 2;
            return (double)merged[mid];
        } else{
            int mid1 = merged_size / 2;
            int mid2 = (merged_size / 2) - 1;
            return ((double)merged[mid1] + (double)merged[mid2]) / 2.0;
        }
    }
};