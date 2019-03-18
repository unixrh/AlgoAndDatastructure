/* 题目：有一副由NxN矩阵表示的图像，这里每个像素用一个int表示，请编写一个算法，在不占用额外内存空间的情况下(即不使用缓存矩阵)，将图像顺时针旋转90度。
 * 解法：注意定义 剩余边长与每次的迭代变量; 下标有规律可循，每次的横纵坐标可以直接抄
 */
#include <iostream>
#include <stdio.h>

using namespace std;

#define N 5

void rotateMatrix(int mat[N][N]) {
  for(int i = N; i > 0; i-=2){
    int step = (N - i) / 2 + 1;
    for(int j = step-1; j < N - step; j++) {
      int tmp = mat[j][N-step];
      mat[j][N-step] = mat[N-step][N-j-1];
      mat[N-step][N-j-1] = mat[N-j-1][step-1];
      mat[N-j-1][step-1] = mat[step-1][j];
      mat[step-1][j] = tmp;
    }
  }
}

void printArray(int arr[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }

}

int main(int argc, char* argv[]) {
  int arr[N][N] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
  };
  printArray(arr);
  rotateMatrix(arr);
  printArray(arr);
  return 0;
}

