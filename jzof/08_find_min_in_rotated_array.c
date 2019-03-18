/* 题目：将一个递增排序的数组旋转，试着找出其中的最小值
 * 解法：使用一头一尾两个指针，与中间的数作比较而相应第移动指针位置。最终右边的指针指向的就是最小值，左边的指针指向的是最大值。
 */
#include <stdio.h>

int getMin(int arr[], int length) {
  int i = 0, j = length - 1;
  int mid = length / 2;
  while(i < j) {
    printf("mid:%d\t%d\t%d\n", i, mid, j);
    if(arr[i] < arr[mid]) {
      i = mid;
      mid = (i+j) / 2;
    } else if(arr[j] > arr[mid]) {
      j = mid;
      mid = (i+j) / 2;
    } else {
      break;
    }
  }

  return arr[j];
}

int main(int argc, char* argv[]) {
  int bp = atoi(argv[1]);
  int a[9] = {0};
  for(int i = 0; i < 9; i++) {
    if(i < bp)
      a[i] = i+9-bp;
    else
      a[i] = i-bp;
  }
  for(int i = 0; i < 9; i++) {
    printf("%d\t", a[i]);
  }
  printf("\n");
  printf("%d\n", getMin(a, 9));
  return 0;
}
