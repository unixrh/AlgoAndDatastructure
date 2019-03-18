/* 题目: 给定两个长度为n的数组，weight表示n个物品对应的重量，value表示n个物品对应的价值，现有一个背包容量为W，找出背包能装下的物品集合，使之价值最大化；
 * 解法：动态规划。
 *       使用dp[j]表示当背包容量为j时所能容纳的最大价值;
 *       对于任意第i个物品，都可能放与不放；
 *       当j>=weight[i]时，dp[j] 从以下两者中取较大者：
 *            1、不放入这个物品的结果值（即上一个dp[j]） 
 *            2、这个物品的价值+这个物品所占容量以外的容量能容纳的最大价值
 * */

#include <iostream>

using namespace std;

#define MAX_CAPACITY  1000
#define NUM 4
int max(int a, int b) {
  return a > b ? a : b;
}

int knapsack(int n, int weight[], int value[], int capacity) {
  int dp[MAX_CAPACITY] = {0};
  for(int i = 0; i < n; i++) {
    for(int j = capacity; j > 0; j--) {
      if(j >= weight[i]) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
      }
    }
  }
  return dp[capacity];
}

int main(int argc, char* argv[]) {
  int weight[NUM] = {10, 20, 30, 40};
  int value[NUM] = {60, 100, 120, 200};
  int capacity = 80;
  cout << "the max value is: " << knapsack(NUM, weight, value, capacity) << endl;
}
