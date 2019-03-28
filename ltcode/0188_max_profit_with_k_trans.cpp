/* 给定整型数组prices，代表一支股票的股价；你可以最多交易k次，试求最大的利润
 * 设定 buy[i] 第i次购买后的最大利润，为 max(sell[i-1] - curPrice, buy[i]);
 * 表示上次卖完之后，买下当前股价之后剩余
 * sell[i]第i次出售后的最大利润，为max(buy[i]+curPrice, sell[i]); 
 * 表示上次买完之后，卖出当前股价之后剩余
 * 这里的一维数组，意味着各元素在每次增加交易的遍历中会被更新
 */
#include <iostream>
#include <vector>
using namespace std;
int maxProfit(int k, vector<int> &prices) {
  int n = prices.size();
  if(k > n/2) {
    int sum = 0;
    for(int i = 1; i < n; i++) {
      if(prices[i] > prices[i-1]) {
        sum += prices[i] - prices[i-1];
      }
    }
    return sum;
  }

  vector<int> buy(k+1, INT_MIN);
  vector<int> sell(k+1, 0);
  for(auto curPrice : prices) {
    for(int i = 1; i <= k; i++) {
      buy[i] = max(sell[i-1] - curPrice, buy[i]);
      sell[i] = max(buy[i] + curPrice, sell[i]);
    }
  }
  return sell[k];
}
