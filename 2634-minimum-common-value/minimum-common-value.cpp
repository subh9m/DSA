class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int common = -1;
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0;
        int j = 0;

        while(i < n1 && j < n2){
            if(nums1[i] == nums2[j]){
                common = nums1[i];
                break;
            }else if(nums1[i] < nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        return common;
    }
};