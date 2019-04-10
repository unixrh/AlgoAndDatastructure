/*  在旋转数组中查找
 *  思路：对比0033题，它要处理mid与l与r均相等的情况，此时，另r--,l++再继续
 */
class Solution {
public:
    int helper(vector<int>& arr, int target, int l, int r) {
        while(l <= r) {            
            int mid = l + ((r-l) >> 1);            
            cout << l << r << mid << endl;
            if(arr[mid] == target) return true;
            if(arr[l] == arr[r] && arr[l] == arr[mid]) {
                r--;
                l++;
                continue;
            }
            if(arr[mid] >= arr[l]) {
               if(arr[l] <= target && arr[mid] > target) { // 单调递增且target在其中
                    r = mid-1;
                } else {
                   l = mid+1;
               }
            } else {
                if(arr[mid] < target && arr[r] >= target) { // 非单调递增且target在其中
                   l = mid+1;
                } else {
                   r = mid-1;
               }
            }
        }
        return false;
    }    
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        return helper(nums, target, 0, nums.size()-1);
    }
};
