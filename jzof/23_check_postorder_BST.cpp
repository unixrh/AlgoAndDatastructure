#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> arr, int l, int r) {
  if(l >= r)
    return true;
  int key = arr[r];
  int i = l;
  for(i = l; i < r; i++) {
    if(arr[i] > key)
      break;
  }
  for(int j = i; j < r; j++)
    if(arr[j] < key)
      return false;
  return check(arr, l, i - 1) && check(arr, i, r-1);
}

int main() {
  vector<int> arr = {2, 9, 5, 16, 17, 15, 19, 18, 12};
  vector<int> arr1 = {5,7,6,9,11,10,8};
  vector<int> arr2 = {7,4,6,5};
  cout << check(arr, 0, arr.size() - 1) << endl;
  cout << check(arr1, 0, arr1.size() - 1) << endl;
  cout << check(arr2, 0, arr2.size() - 1) << endl;
  return 0;
}
