/*使用栈+循环实现快排
 */
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &vec, int l, int r) {
  int index = l + ((r-l) >> 1);
  swap(vec[index], vec[r]);
  int small = l - 1;
  while(l < r) {
    if(vec[l] <= vec[r]) {
      small++;
      swap(vec[l], vec[small]);
    }
    l++;
  }
  small++;
  swap(vec[r], vec[small]);
  return small;
}

void quicksort(vector<int> &vec, int l, int r) {
  if(l < r) {
    int pivot = partition(vec, l, r);
    quicksort(vec, l, pivot - 1);
    quicksort(vec, pivot + 1, r);
  }
}

void quicksort_iterative(vector<int> &vec, int l, int r) {
  // vector<int> stack(r-l+1, 0);
  int stack[r-l+1];
  int top = -1;
  stack[++top] = l;
  stack[++top] = r;
  while(top >= 0) {
    r = stack[top--];
    l = stack[top--];
    int pivot = partition(vec, l, r);
    if(pivot-1 > l) {
      stack[++top] = l;
      stack[++top] = pivot - 1;
    }
    if(pivot+1 < r) {
      stack[++top] = pivot + 1;
      stack[++top] = r;
    }
  }
}

int main() {
  vector<int> vec{12,3,4,7,2,5,6};
  int l = 0;
  int r = vec.size() - 1;
  // quicksort(vec, l , r);
  quicksort_iterative(vec, l , r);
  for(auto item : vec)
    cout << item << endl;
  return 0;
}

