/* 题目：给定1分，5分，10分({V1, V2, ..., Vm}) 的硬币(数量不限)，求能够拼成N分的最少硬币数量
 * 解法：假设dp[i][sum]为使用前i种硬币拼成sum分所需的最少硬币数量
 *       则dp[i][sum] = dp[i-1][sum-coin[i]] + 1 
 *       加入一个当前的硬币，再加上除去当前硬币时之前已算出的最小值
 */

#include <iostream>

using namespace std;
#define MAX_SUM 10000
#define NUM 6

// dp1是我的思路，也是work的，并且在我看来更加直观，代价是多一个数组
int getNum(int coins[], int sum) {
  int dp[MAX_SUM + 1] = {1};
  int dp1[MAX_SUM + 1] = {MAX_SUM};
  dp[0] = 0;
  for(int j = 1; j <= MAX_SUM; j++) {
    dp[j] = 1;
    dp1[j] = 9999;
  }
  for(int j = 0; j < NUM; j++) {
    dp1[coins[j]] = 1;
  }
  for(int i = 0; i < NUM; i++) {
    for(int j = 1; j <= sum; j++) {
      if(j >= coins[i])
        //dp[j] = min(dp[coins[i]], dp1[j]) + dp[j-coins[i]];
        dp[j] = 1 + dp[j-coins[i]];
      cout << dp[j] << "-";
    }
    cout << endl;
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
