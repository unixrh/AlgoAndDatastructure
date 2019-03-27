/* 找出字符串各异字符子序列的数量
 * 重点在于找出每次增加一个字符时可能带来的总数变化；可以考虑记录下某字符结尾的序列的数量；
 */
#include <iostream>
using namespace std;
class Solution {
public:
    int distinctSubseqII(string S) {
      int mod = 1e9 + 7;
      int res = 0, add = 0;
      int record[26] = {};
      for(auto c : S){
        add = (res - record[c-'a'] + 1) % mod;
        res = (add + res) % mod;
        record[c-'a'] = (add + record[c-'a']) % mod;
      }
      return (res+mod)%mod;
    }
};
