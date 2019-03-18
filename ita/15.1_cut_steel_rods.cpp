/* 题目：给定一个钢条的每段的售价，求问一个长度为total的钢条最多能卖多少钱；
 * 解法：动态规划，这里我的算法貌似比较优化一些。我将开始的价格初始化到数组中，然后在遍历j时只要遍历i的一半。
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define NUM 10
static int types[NUM] = {1,2,3,4,5,6,7,8,9,10};
static int prices[NUM] = {1,5,8,9,10,17,17,20,24,30};

int getPrice(int total) {
  vector<int> res(total+1);
  for(int i = 1; i < res.size(); i++) {
    if(i <= NUM && types[i-1] <= total){
      res[i] = prices[i-1];
    }
  }
  for(auto item : res) {
    cout << item << " xxx ";
  }
  cout << endl;
  for(int i = 1; i <= total; i++) {
    int cmax = res[i];
    for(int j = 0; j <= i/2; j++) {
      cmax = max(cmax, res[i-j] + res[j]);
    }
    res[i] = cmax;
  }
  return res[total];
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << argv[0] << " len" << endl;
    exit(1);
  }
  int len = atoi(argv[1]);
  int i = len;
  for(i = 0;i < len; i++)
    cout << i << "-" << getPrice(i) << endl;
  return 0;
}
