/* 题目：将数组中的奇数都排在偶数之前
 * 解法：前后两个指针，交换
 */
#include "../common/utils.h"

void sort(int arr[], int n) {
  int l = 0, r = n - 1;
  while(l < r) {
    while(arr[l] & 1 && l < r) {
      l++;
    }
    while((arr[r] & 1) == 0 && l < r) { // & 的符号优先级比 == 低，注意加上括号
      r--;
    }
    swap(arr[l], arr[r]);
  }
}


int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "usage: " << argv[0] << " num" << endl;
    exit(0);
  }
  int n = atoi(argv[1]);
  int *arr = CommonUtils::createIntArrOfSizeN(n);
  CommonUtils::printArr(arr, n);
  sort(arr, n);
  CommonUtils::printArr(arr, n);
  return 0;
}
