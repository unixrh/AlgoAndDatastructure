/* 题目： 找出有序数组中下标与值相同的元素；
 * 解法： O(N)顺序查找是很弱的解法。应该利用有序的特点进行二分，但是要注意数组中有重复的内容
 */
#include <iostream>
#include <vector>
using namespace std;

int get(vector<int> arr, int l, int r) {
  if(l > r) {
    return INT_MIN;
  }
  int mid = (l+r)/2;
  if(arr[mid] == mid) 
    return mid;
  else if(arr[mid] > mid) {
    return get(arr, l, mid - 1);
  } else {
    return get(arr, mid+1, r);
  }
}

int getWithDup(vector<int> arr, int l, int r) {
  if(l > r)
    return INT_MIN;

  int mid = (l+r)/2;
  int midValue = arr[mid];

  if(midValue == mid)
    return mid;

  int leftIndex = min(mid - 1, midValue);

  int left = getWithDup(arr, l, leftIndex);
  if(left > INT_MIN)
    return left;

  int rightIndex = max(mid + 1, midValue);
  int right = getWithDup(arr, rightIndex, r);
  if(right > INT_MIN)
    return right;
  return INT_MIN;
}

int main() {
  // vector<int> a{-40, -20, INT_MIN, 1, 2, 3, 5, 7, 9, 12, 13};
  vector<int> a{-40, -20, INT_MIN, 1, 2, 3, 5, 8, 9, 12, 13};
  cout << get(a, 0, a.size() - 1) << endl;
  vector<int> b{-1, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};
  cout << getWithDup(b, 0, b.size() - 1) << endl;
  return 0;
}
