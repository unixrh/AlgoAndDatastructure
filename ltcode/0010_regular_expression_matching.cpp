/* 题目：给定字符串s和规则p，判断s是否符合规则p，其中p的.表示任意字母，其中p的*表示重复任意次数(包括0)的前一个字符
 * 解法：使用dp[i][j]代表s[0...i-1]与p[0...j-1]的匹配结果。
 *       对于p的j-1字符为.或者p的j-1字符与s的i-1字符相同时，只要完全依赖于上一个字符的匹配结果；即dp[i][j] = dp[i-1][j-1]
 *       若p的j-1字符为*:
 *                        若出现0次，只要与上上次结果相比 即 dp[i][j] = dp[i][j-2]
 *                        若出现>=1次，则需要s[i-1] 与 p[j-2]相等或者p[j-2]为.，同时dp[i-1][j]==true(因为认为匹配多个当前值，则减去s当前的字符也无妨)
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    static bool isMatch(string s, string p) {
      int slen = s.size();
      int plen = p.size();
      vector<vector<bool> > dp(slen+1, vector<bool>(plen+1, false));
      dp[0][0] = true;
      for(int i = 1; i <= plen; i++) {
        if(p[i-1] == '*')
          dp[0][i] = dp[0][i-2];
      }
      for(int i = 1; i <= slen; i++) {
        for(int j = 1; j <= plen; j++) {
          if(p[j-1] == '.' || p[j-1] == s[i-1]) {
            dp[i][j] = dp[i-1][j-1];
          } else if(p[j-1] == '*') {
            dp[i][j] = dp[i][j-2];
            if(p[j-2] == '.' || p[j-2] == s[i-1])
              dp[i][j] = dp[i][j] || dp[i-1][j];
          } else {
            dp[i][j] = false;
          }
        }
      }
      return dp[slen][plen];
    }
};

int main() {
  cout << Solution::isMatch("aa", "a") << endl;
  cout << Solution::isMatch("aa", "a*") << endl;
  return 0;
}
