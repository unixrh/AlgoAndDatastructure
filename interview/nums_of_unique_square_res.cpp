#include <iostream>
#include <vector>

using namespace std;

int abs(int a) {
  return a > 0 ? a : (0-a);
}

int solve(vector<int> arr) {
  if(arr.size() <= 1) {
    return arr.size();
  }

  size_t res = 1;

  int i = 0, j = arr.size() - 1;

  while(i < j) {
    int num1 = abs(arr[i]);
    int num2 = abs(arr[j]);
    if(num2 > num1) {
      res += 1;
      j--;
      while(abs(arr[i]) == num1 && i < j) {
        i++;
      }
    } else {
      i++;
    }
  }
  return res;
}

int main(){
  vector<int> vec{-1, 0, 1, 2};
  cout << solve(vec) << endl;
  return 0;
}
