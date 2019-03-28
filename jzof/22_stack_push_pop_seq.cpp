/* 给定两个序列，in和out，in为入栈序列，判断out是否为in的一个出栈序列
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool check(vector<int> &in, vector<int> &out) {
  stack<int> st;
  int j = 0, i = 0;
  while(j < in.size() && i < out.size()) {
    if(in[j] != out[i])
      st.push(in[j]);
    else 
      i++;
    j++;
  }
  while(i < out.size() && !st.empty()) {
    if(out[i++] == st.top()) st.pop();
    else break;
  }
  cout << i << st.size() << endl;;
  return i == out.size() && st.empty();
}

int main() {
  vector<int> in{1,2,3,4,5};
  vector<int> out1{4,5,3,2,1};
  vector<int> out2{4,3,5,1,2};
  cout << check(in, out1) << endl;
  cout << check(in, out2) << endl;
  return 0;
}
