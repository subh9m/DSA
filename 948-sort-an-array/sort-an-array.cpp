class Solution {
public:
    void merge(vector<int>&nums, int left, int mid, int right){
        int n = mid - left + 1;
        int m = right - mid;

        vector<int>a;
        vector<int>b;
        for(int i = 0; i < n; i++){
            a.push_back(nums[left+i]);
        }

        for(int i = 0; i < m; i++){
            b.push_back(nums[mid+1+i]);
        }

        int i = 0;
        int j = 0;
        int k = left;
        while(i < n && j < m){
            if(a[i] <= b[j]){
                nums[k] = a[i];
                i++;
            } else{
                nums[k] = b[j];
                j++;
            }
            k++;
        }

        while(i < n){
            nums[k] = a[i];
            i++;
            k++;
        }

        while(j < m){
            nums[k] = b[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>&nums, int left, int right){
        if(left < right){
            int mid = left + (right - left)/2;

            mergeSort(nums, left, mid);
            mergeSort(nums, mid+1, right);

            merge(nums, left, mid, right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0, nums.size()-1);
        return nums;
    }
};