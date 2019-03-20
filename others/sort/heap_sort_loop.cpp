/* 堆的实现与堆排序
 * 从中间开始往头部走，对比自身与左右子节点的大小，并递归地下沉
 * 排序时，头部已有堆属性，将它与最后一个交换，然后将头部堆化
 * 如果有新加的，则加到尾部，然后逐渐替换式上升
 */
#include "../../common/utils.h"

// 使得较小的下沉
void heapify(int arr[], int num, int i) {
  int pivot = i;
  int l = 2*i + 1;
  int r = 2*i + 2;
  if(l < num && arr[l] > arr[pivot])
    pivot = l;
  if(r < num && arr[r] > arr[pivot])
    pivot = r;
  if(pivot != i){
    swap(arr[pivot], arr[i]);
    heapify(arr, num, pivot);
  }
}

// 使得较大的上浮
void siftup(int arr[], int num, int i){
  arr[num-1] = i;
  int tmp = num - 1;
  while(tmp) {
    int parent = (tmp - 1) >> 1;
    if(arr[parent] < arr[tmp]) {
      swap(arr[tmp], arr[parent]);
      tmp = parent;
    } else 
      break;
  }
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "usage: " << argv[0] << " num" << endl;
    exit(1);
  }
  int num = atoi(argv[1]);
  int *arr = CommonUtils::createIntArrOfSizeN(num, 10);
  CommonUtils::printArr(arr, num, "input ");
  for(int i = num/2-1; i >= 0; i--)
    heapify(arr, num, i);
  CommonUtils::printArr(arr, num, "heapify: ");
  int *arr1 = CommonUtils::createIntArrOfSizeN(num+1, 10);
  num = num + 1;
  for(int i = 0; i < num; i++)
    arr1[i] = arr[i];
  siftup(arr1, num, num*5);
  CommonUtils::printArr(arr1, num, "add: ");
  for(int i = num - 1; i >= 0; i--) {
    swap(arr1[0], arr1[i]);
    heapify(arr1, i, 0);
  }
  CommonUtils::printArr(arr1, num, "output");
  return 0;
}
