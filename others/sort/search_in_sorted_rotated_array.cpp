/* 题目：在一个排序后旋转的数组中找出某个数的index，若找不到则返回-1
 * 解法：先用二分法找出旋转点，然后对旋转点做二分递归；二分法找中间节点的时候，可以考虑用(r-l) /2 + l;这样可以避免超出整数取值范围；
 */
#include <iostream>

using namespace std;

#define LEN 10
int arr[LEN] = {8,10,12,14,16,18,0,2,4,6};

int findPivot(int arr[], int l, int r) {
  if(l > r) {
    return -1;
  }
  int mid = (l+r) / 2;
  cout << l << mid << r << endl;
  if(mid < r && arr[mid] > arr[mid+1])
    return mid;
  if(mid > l && arr[mid] < arr[mid-1])
    return mid - 1;
  if(arr[mid] >= arr[l]) {
    return findPivot(arr, mid + 1, r);
  }
  return findPivot(arr,  l, mid - 1);
}

int bin_search(int target, int l, int r) {
  if(l > r)
    return -1;
  int mid = (l+r) / 2;
  if(arr[mid] == target) {
    return mid;
  } else if(arr[mid] < target) {
    return bin_search(target, mid+1, r);
  } else {
    return bin_search(target, l, mid-1);
  }
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "usage: " << argv[0] << " num" << endl;
    exit(1);
  }

  int target = atoi(argv[1]);
  int pivot = findPivot(arr, 0, LEN-1);
  if(pivot == -1)
    cout << bin_search(target, 0, LEN-1) << endl;
  if(target == arr[pivot]) {
    cout << pivot << endl;;
  }
  if(target >= arr[0]) {
    cout << bin_search(target, 0, pivot-1) << endl;
  }
  cout << bin_search(target, pivot+1, LEN-1) << endl;
}
