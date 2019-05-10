#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<int> &arr) {
  int maxending = 0;
  int res = 0;
  for(auto i : arr) {
    maxending = max(maxending + i, 0);
    res = max(res, maxending);
  }
  return res;
}

int main() {
  vector<int> arr{-1, 2, 3, -8, 9, -2, 1, 2, -4};
  cout << solve(arr) << endl;
  return 0;
}
