/* 题目：给定两个字符串s、t，求t的每个字符在s的各异子序列中出现的次数
 * 解法：动态规划， 横轴为s的各个字符，纵轴为t的各个字符。
 *       如果当前比较的字符相等，则res[i][j] = res[i-1][j-1] + res[i][j-1]; 
 *       比如 s = "bagabag", t = "bag";可以先把第一行和第一列初始化出来
 *        bagabag
 *       b1111222
 *       a0112244
 *       g0011115
 *       考虑右下角数字的产生，可以参考已经获得的结果4和1
 *       因为bagaba中有4个ba，那么当两者再出现一个g时，就能多产生4个bag。
 *       因此答案为 4+1
 */
#include <iostream>
#include <vector>

using namespace std;

int getNumOfDistinctSubseq(string s, string t) {
  int rowNum = t.size();
  int colNum = s.size();
  if(rowNum == 0 || colNum == 0) 
    return 0;
  vector<vector<int> > res(rowNum, vector<int>(colNum, 0));
  if(s[0] == t[0])
    res[0][0] = 1;
  for(int i = 1; i < colNum; i++) {
    if(t[0] == s[i])
      res[0][i] = res[0][i-1] + 1;
    else
      res[0][i] = res[0][i-1];
  }
  for(int i = 1; i < rowNum; i++) {
      res[i][0] = 0;
  }
  for(int i = 1; i < rowNum; i++) {
    for(int j = 1; j < colNum; j++) {
      if(s[j] == t[i])
        res[i][j] = res[i-1][j-1] + res[i][j-1];
      else
        res[i][j] = res[i][j-1];
    }
  }
  return res[rowNum-1][colNum-1];
}

int main(int argc, char* argv[]) {
  string s = argv[1];
  string t = argv[2];
  cout << getNumOfDistinctSubseq(s, t) << endl;
}
