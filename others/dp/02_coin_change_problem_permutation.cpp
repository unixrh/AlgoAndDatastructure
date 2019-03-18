/* 题目：给定1分，5分，10分({V1, V2, ..., Vm})的硬币，求能够拼成N分的组合数量
 * 解法：动态规划。
 *       假设dp[sum]为拼成sum分的组合数量；
 *       dp[sum] = dp[sum - 0*Vm] + dp[sum - 1*Vm]+ dp[sum - 2*Vm] + ... + dp[sum - K*Vm]; 其中K = sum / Vm
 **/

#include <iostream>

using namespace std;
#define MAX_SUM 10000
#define NUM 6

int getNum(int coins[], int sum) {
  int dp[MAX_SUM + 1] = {0};
  dp[0] = 1;
  for(int i = 0; i < NUM; i++) {
    for(int j = coins[i]; j <= sum; j++) {
      dp[j] = dp[j] + dp[j-coins[i]];
    }
  }
  return dp[sum];
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "pls input: " << endl;
    exit(1);
  }

  int coins[NUM] = {1,5,10,20,50,100};
  int sum = atoi(argv[1]);
  cout << getNum(coins, sum) << endl;
  return 0;
}
