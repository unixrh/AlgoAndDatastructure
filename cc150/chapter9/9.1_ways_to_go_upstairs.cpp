/* 题目：上楼梯，可以一次走1、2、3步，问走到第N个台阶有几种走法。
 * 解法：从终点反推：比如走到第10个台阶，可以从第9个、第8个、第7个走上去。因此 f(10)=f(9)+f(8)+f(7)
 *       如果使用递归，则O(N^3)；应该动态规。
 */
#include <iostream>
#include <vector>

using namespace std;
int waysToUpstairs(int total) {
  if(total <= 3)
    return max(1, total);
  else
    return waysToUpstairs(total-1) + waysToUpstairs(total-2) + waysToUpstairs(total-3);
}

int waysToUpstairs1(int total) {
  if(total <= 3)
    return max(0, total);
  vector<int> a(total+1);
  a[0] = 1;
  a[1] = 1;
  a[2] = 2;
  a[3] = 4;

  for(int i = 4; i <= total; i++) {
    a[i] = a[i-1] + a[i-2] + a[i-3];
  }
  return a[total];
}

