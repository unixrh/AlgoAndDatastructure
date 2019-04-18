#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &vec, int l, int r) {
  int z = 0;
  while(l <= r) {
    if(vec[l] == 0) {
      swap(vec[z++], vec[l++]); 
    }else if(vec[l] == 1) {
      swap(vec[r--], vec[l]); 
    } else {
      l++;
    }
  }
}

int main(){
  vector<int> vec{1, 0, 2, 2, 0, 0, 1, 2, 1, 1, 0};
  sort(vec, 0, vec.size() - 1);
  for(auto i : vec) {
    cout << i << endl;
  }
  return 0;
}
