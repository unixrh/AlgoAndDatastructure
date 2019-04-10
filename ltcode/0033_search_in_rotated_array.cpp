/* 在旋转过的数组中查找
 * 思路：关键在于对于每个mid，对它进行判断，看它是否在单调区间
 */
class Solution {
  public:
    int search(vector<int>& nums, int target) {
      if(nums.size() == 0) return -1;
      int l = 0, r = nums.size() - 1;
      int mid = l;
      while(l <= r) {
        mid = l + ((r-l) >> 1);
        cout << l << "-" << mid << "-" << r << endl;
        if(nums[mid] == target) {
          return mid;
        }
        // mid处于单调递增区间
        if(nums[l] <= nums[mid]) {
          if(nums[l] <= target && target < nums[mid] ) {
            r = mid - 1;
          } else {
            l = mid + 1;
          }
        } else { // 不处于单调递增区间
          if(nums[r] >= target && target > nums[mid] ) {
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
      }
      return -1;
    }
};
