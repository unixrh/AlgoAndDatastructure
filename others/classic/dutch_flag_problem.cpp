/* 荷兰国旗问题： 如何将三个颜色归类
 * 一个数组中，只有数字0，1，2；如何将他们按0，2，1的顺序聚类
 * 思路：使用三个指针，遍历的指针，每次遇到0都和左指针交换，并且两者同时前进；每次遇到1都和右指针交换，右指针左移，遍历指针不动；
 */
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;
vector<int> createIntArrOfSizeN(int n) {
  vector<int> arr;
  srand(time(NULL));
  for(int i = 0; i < n; i++) {
    arr.push_back(rand() % 3);
  }
  return arr;
}

void range(vector<int> &arr) {
  int z = 0, i = 0, r = arr.size()-1;
  while(i <= r) {
    if(arr[i] == 0) {
      swap(arr[i++], arr[z++]);
    } else if (arr[i] == 1) {
      swap(arr[i], arr[r--]);
    } else {
      i++;
    }
  }
}

int main() {
  vector<int> arr = createIntArrOfSizeN(19);
  for(auto item : arr) {
    cout << item << " ";
  }
  cout << endl;
  range(arr);
  for(auto item : arr) {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}
