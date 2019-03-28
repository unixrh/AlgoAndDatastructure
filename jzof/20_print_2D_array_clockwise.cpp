/* 顺时针打印二维数组
 * 给函数传入左上和右下角的坐标，每次按照顺时针先打印一圈，然后递归。
 */
#include <iostream>
#include <vector>

using namespace std;

void printClockwise(vector<vector<int> > &matrix, int x1, int y1, int x2, int y2) {
  if(x1 > x2 || y1 > y2) {
    return;
  }
  for(int i = y1; i <= y2; i++) {
    cout << matrix[x1][i] << " ";
  }
  for(int i = x1+1; i <= x2; i++) {
    cout << matrix[i][y2] << " ";
  }

  if(x1 == x2 || y1 == y2) return; // 如果只有一行或者一列，就不用继续了
  for(int i = y2-1; i >= y1; i--) {
    cout << matrix[x2][i] << " ";
  }
  for(int i = x2-1; i >= x1+1; i--) {
    cout << matrix[i][y1] << " ";
  }
  printClockwise(matrix, x1+1, y1+1, x2-1, y2-1);
}

int main(){
  vector<vector<int> > matrix = {
   // {1, 2, 3, 4, 5},
   // {6, 7, 8, 9, 10},
   // {11, 12, 13, 14, 15},
   // {16, 17, 18, 19, 20},
   // {21, 22, 23, 24, 25}
   {1}, 
   {6}, 
   {11},
   {16},
   {21}
   
  };
  printClockwise(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1);
  return 0;
}
