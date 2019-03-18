/* 获得数组中最大和的子数组
 */
#include <iostream>
#include <vector>

using namespace std;

#define LEN 10

int maxSum(int src[LEN], vector<int>& res) {
  int l = 0, r = 0, sum = 0, max_sum = INT_MIN;
  int max_l = 0, max_r = 0;
  while(r < LEN) {
    sum += src[r];
    r++;
    if(sum <= 0) {
      sum = 0;
      l = r;
    }
    if(sum > max_sum) {
      max_sum = sum;
      max_l = l;
      max_r = r;
    }
  }
  cout << max_l << max_r << endl;
  for(int i = max_l; i < max_r; i++)
    res.push_back(src[i]);
  return max_sum;
}

int main() {
  int arr[LEN] = {2, 3, -8, -1, 2, 4, -2, 3, 6, -3};
  vector<int> res;
  int sum = maxSum(arr, res); 
  cout << sum << endl;
  for(int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}
