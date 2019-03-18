/* 题目：计算最长的有效括号长度
 * 解法：动态规划，从后面开始往前遍历，
 *       若在index遇到左括号，则看s[i+dp[i+1]+1]是否为右括号，
 *       若是，则表明dp[i] = dp[i+1]+2；
 *       同时若i+dp[i+1]+1+1未越界，则dp[i] += dp[i+dp[i+1]+1+1]
 */
#include <iostream>
#include <vector>

using namespace std;

 int longestValidParentheses(string s) {
   int* dp = (int *)malloc(s.size() * sizeof(int) + 1);
   memset(dp, 0, s.size()*sizeof(int));
   // vector<int> dp(s.size(), 0);
   int res = 0;
   for(int i = s.size() - 2; i >= 0; i--){
     if(s[i] == '(') {
       if(i+dp[i+1]+1 < s.size() && s[i+dp[i+1]+1] == ')')
         dp[i] = dp[i+1] + 2;
       if(i+dp[i] < s.size())
         dp[i] += dp[i+dp[i]];
     }
     res = max(res, dp[i]);
   }
   free(dp);
   return res;
 }

int main(int argc, char* argv[]) {
  /*
  if(argc < 2) {
    cout << "usage: " << argv[0] << " str" << endl;
    exit(1);
  }
  */

  string input = ")()()";
  cout << input << endl;

  cout << longestValidParentheses(input) << endl;
}
