/* 找到最小需要排序的子数组
 * 思路：从左往右，找到最右一个小于已有最大值的
 *       从右往左，找到最左一个大于已有最小值的
 */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int get(const vector<int> &vec) {
  int my_max = INT_MIN;
  int my_min = INT_MAX;
  size_t right_index = 0, left_index = vec.size() - 1;
  for(int i = 0; i < vec.size(); i++) {
    my_max = max(my_max, vec[i]);
    if(vec[i] < my_max)
      right_index = i;
  }
  for(int i = vec.size() - 1; i >= 0; i--) {
    my_min = min(my_min, vec[i]);
    if(vec[i] > my_min)
      left_index = i;
  }
  cout << right_index << left_index << endl;
  return right_index - left_index + 1;
}

int main() {
  vector<int> vec{1, 5, 4, 3, 2, 6, 7};
  cout << get(vec) << endl;
  return 0;
}
