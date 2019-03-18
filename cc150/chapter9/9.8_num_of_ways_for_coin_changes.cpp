#include <iostream>
#include <vector>

using namespace std;
int nums(vector<int> arr, vector<int>& res, int total) {
  res[0] = 1;
  for(size_t i = 1; i <= total; i++) {
    res[i] = 0;
  }
  for(size_t i = 0; i < arr.size(); i++) {
    for(int j = arr[i]; j <= total; j++) {
      res[j] = res[j] + res[j-arr[i]];
    }
  }
  return res.back();
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << argv[0] << " num" << endl;
  }
  vector<int> arr{1,5,10,20,50,100};
  int total = atoi(argv[1]);
  vector<int> res(total+1);
  cout << nums(arr, res, total) << endl;
  return 0;
}
