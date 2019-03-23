#include "../../common/utils.h"

using namespace std;

void heapify(int arr[], int len) {
  for(int i = 0; i< len; i++) {
    int j = i;
    while(j > 0) {
      int tmp =  (j-1) / 2;
      if(arr[j] > arr[tmp]) {
        break;
      } else {
        swap(arr[j], arr[tmp]);
        j = tmp;
      }
    }
  }
}

void heapsort(int arr[], int len)
{
  int i = len - 1;
  while(i > 0) {
    swap(arr[0], arr[i]);
    int j = 0;
    while(j < i) {
      int left = 2 * j + 1;
      int right = 2 * j + 2;
      int tmp = j;
      if(left < i && arr[left] < arr[tmp])
        tmp = left;
      if(right < i && arr[right] < arr[tmp])
        tmp = right;
      if(tmp != j) {
        swap(arr[tmp], arr[j]);
        j = tmp;
      } else {
        break;
      }
    }
    i--;
  }
}

int main(int argc, char* argv[]) {
  int arr[14] = {99, 5, 36, 7, 22, 17, 46, 12, 2, 19, 25, 28, 1};
  CommonUtils::printArr(arr, 14);
  heapify(arr, 14);
  CommonUtils::printArr(arr, 14);
  heapsort(arr, 14);
  CommonUtils::printArr(arr, 14);
}
