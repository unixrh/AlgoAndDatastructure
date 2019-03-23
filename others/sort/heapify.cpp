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

int main(int argc, char* argv[]) {
  int arr[14] = {99, 5, 36, 7, 22, 17, 46, 12, 2, 19, 25, 28, 1};
  CommonUtils::printArr(arr, 14);
  heapify(arr, 14);
  CommonUtils::printArr(arr, 14);
}
