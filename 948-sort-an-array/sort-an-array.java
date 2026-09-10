class Solution {
    public void merge(int[] nums, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        List<Integer>list = new ArrayList<>();

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                list.add(nums[left]);
                left++;
            } else {
                list.add(nums[right]);
                right++;
            }
        }

        while(left <= mid){
            list.add(nums[left]);
            left++;
        } 

        while(right <= high){
            list.add(nums[right]);
            right++;
        }


        for(int i = low; i <= high; i++){
            nums[i] =  list.get(i-low);
        }

    }
    public void mergeSortHelper(int[] nums, int low, int high){
        if(low >= high) return;

        int mid = (low + high) / 2;
        mergeSortHelper(nums, low, mid);
        mergeSortHelper(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    public int[] sortArray(int[] nums) {
        int n = nums.length;

        mergeSortHelper(nums, 0, n-1);
        return nums;
    }
}