/* 题目： 给定一个包含正整数和负整数的矩阵，找出总和最大的子矩阵
 * 解法： 指定rowStart和rowEnd，将每行的和相加成为1维数组，题目就变成了寻找最大的子数组
 */

#include <iostream>
#include <vector>

using namespace std;

int getMaxSumSubArr(vector<int> arr) {
  int res = arr[0];
  int tmpSum = 0;
  for(int i = 0; i < arr.size(); i++) {
    tmpSum += arr[i];
    res = max(res, tmpSum);
    if(tmpSum < 0)
      tmpSum = 0;
  }
  return res;
}

int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
  if(matrix.size() == 0) return -1;
  int maxSum = INT_MIN;
  int rowNum = matrix.size();
  int colNum = matrix[0].size();
  for(int rowStart = 0; rowStart < rowNum; rowStart++) {
    vector<int> helper(colNum, 0);
    for(int rowEnd = rowStart; rowEnd < rowNum; rowEnd++) {
      for(int i = 0; i< colNum; i++) {
        helper[i] += matrix[rowEnd][i];
      }
      maxSum = getMaxSumSubArr(helper);
    }
  }
  return maxSum;
}

int main() {
  vector<int> arr{-12, -3, -8, -1, -2, -4, -2, -3, -6, -3};
  cout << getMaxSumSubArr(arr) << endl;
  return 0;
}
