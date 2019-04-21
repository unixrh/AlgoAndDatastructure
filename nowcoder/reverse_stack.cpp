#include <iostream>
#include <stack>

using namespace std;

// 从栈中拿走栈底的元素
int get(stack<int> &st) {
  int res = st.top();
  st.pop();
  if(st.empty())
    return res;
  int last = get(st);
  st.push(res);
  return last;
}

// 每次拿出栈底元素，然后最新拿出的最晚push进去
void reverse(stack<int> &st) {
  if(st.empty()) {
    return;
  }
  int i = get(st);
  reverse(st);
  st.push(i);
}
