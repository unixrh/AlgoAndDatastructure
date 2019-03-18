/* 题目：若M X N 的矩阵中，若某元素为零，则将其所在的行与列都清空
 * 解法：注意要用一个辅助数组表明哪些是原有的零，据此准确清零
 *
 */

#include <iostream>
#define M 4
#define N 5

using namespace std;
void printArray(int arr[M][N]) {
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      printf("%5d", arr[i][j]);
    }
    printf("\n");
  }
}

void setZero(int arr[M][N], int row, int col) {
    for(int i = 0; i < M; i++) { 
        arr[i][col] = 0;
    }
    for(int j = 0; j < N; j++) { 
        arr[row][j] = 0;
    }
}

void clearZero(int arr[M][N]){
  int flag[M][N];
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      if(arr[i][j] == 0)
        flag[i][j] = 1;
      else {
        flag[i][j] = 0;
      }
    }
  }
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) { 
      if(flag[i][j] == 1)
        setZero(arr, i, j);
    }
  }
}

int main(int argc, char* argv[]) {
  int arr[M][N] = {
    {1,  2,  3,  4, 5},
    {6,  7,  0,  9, 10},
    {11, 12, 13, 0, 15},
    {16, 17, 18, 19, 20}
  };
  printArray(arr);
  clearZero(arr);
  printArray(arr);

  return 0;
}
