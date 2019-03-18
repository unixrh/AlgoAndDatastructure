/* 题目：八皇后问题
 * 解法：这个题目的关键点应该在于使用一维数组来做空间上的优化。
 */
#include <iostream>
#include <vector>
#include <algorithm>

#define NUM 8
using namespace std;

bool checkValid(const vector<int> columns, int row, int col) {
  for(int i = 0; i < row; i++) {
    if(columns[i] == col)
      return false;
    if(abs(col - columns[i]) == row-i)
      return false;
  }
  return true;
}

void place(int row, vector<int>& columns, vector<vector<int> >& res) {
  if(row == NUM) {
    res.push_back(columns);
  } else {
    for(int col = 0; col < NUM; col++) {
      if(checkValid(columns, row, col)) {
        columns[row] = col;
        place(row+1, columns, res);
      }
    }
  }
}

int main() {
  vector<vector<int> > res;
  vector<int> columns(NUM);
  place(0, columns, res);
  static int count = 0;
  cout << res.size() << endl;
  for(int i = 0; i < res.size(); i++) {
    for(int j = 0; j < res[i].size(); j++) {
      /*
      for(int k = 0; k < res[i].size(); k++) {
        if(k != res[i][j])
          cout << 0 << "  ";
        else
          cout << 1 << "  ";
      }
      */
      cout << res[i][j] << "  ";
      cout << endl;
    }
    cout << ++count << endl;
  }
}
