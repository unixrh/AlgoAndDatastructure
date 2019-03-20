#include "../../common/utils.h"

int partition(int arr[], int l, int r) {
  int pivot = arr[l];
  while(l < r) {
    while(arr[r] >= pivot && l < r)
      r--;
    arr[l] = arr[r];
    while(arr[l] <= pivot && l < r)
      l++;
    arr[r] = arr[l];
  }
  arr[r] = pivot;
  return r;
}

void quick_sort(int arr[], int l, int r) {
  if(l >= r)
    return;
  int pivot = partition(arr, l, r);
  quick_sort(arr, l, pivot - 1);
  quick_sort(arr, pivot + 1, r);
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "usage: " << argv[0] << " num" << endl;
    exit(1);
  }

  int num = atoi(argv[1]);
  int *arr = CommonUtils::createIntArrOfSizeN(num);
  CommonUtils::printArr(arr, num, "input ");
  quick_sort(arr, 0, num-1);
  CommonUtils::printArr(arr, num, "output");
  return 0;
}
