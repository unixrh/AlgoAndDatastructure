class Solution {
public:
    int helper(vector<int>& arr, int target, int l, int r) {
        if(l >= r - 1) {
            if(arr[l] == target) {
                return l;
            } else if (arr[r] == target){
                return r;
            } else {
                return -1;
            }
        }
        int mid = l + ((r-l) >> 1);
        if(arr[mid] > arr[l]) {
           if(arr[l] <= target && arr[mid] >= target) { // 单调递增且target在其中
                r = mid;
            } else {
               l = mid;
           }
        } else {
            if(arr[mid] <= target && arr[r] >= target) { // 非单调递增且target在其中
               l = mid;
            } else {
               r = mid;
           }
        }
        return helper(arr, target, l, r);
    }    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        return helper(nums, target, 0, nums.size()-1);
    }
};
