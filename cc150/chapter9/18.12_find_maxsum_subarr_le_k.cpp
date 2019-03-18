/* 题目： 计算连续子数组之和不大于K的最大和
 * 解法： 使用一个set记录已有[0, i]的和, 则当前累加到j的和curSum - setMember为[i,j]之和
 *        则即我们需要 curSum 截取一段已有的[0, i](假设为x)使得sum[i,j]最接近K；
 *        即curSum - x <= K 也就是 x>=curSum-K. 也就是x = set.lower_bound(curSum - K);
 *        *lower_bound(key)会查找第一个键值不小于key的元素的迭代器。
 */
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int maxSumLeK(vector<int> arr, int k) {
  set<int> accuSet;
  accuSet.insert(0);
  int curSum = 0, curMax = INT_MIN;
  for (int item : arr) {
    curSum += item;
    int tmp = curSum - k;
    set<int>::iterator it = accuSet.lower_bound(tmp); 
    if (it != accuSet.end()) {
      curMax = max(curMax, curSum - *it);
    }
    accuSet.insert(curSum);
  }
  return curMax;
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "usage: " << " k" << endl;
    exit(1);
  }
  vector<int> arr{-9,-4,1, 3, -1,6, -2,-6,6};
  cout << maxSumLeK(arr, atoi(argv[1])) << endl;
  return 0;
}
