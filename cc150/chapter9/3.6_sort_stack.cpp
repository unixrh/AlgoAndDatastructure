/* 题目：对栈s1中的数据进行排序，允许额外使用一个栈
 * 解法：新建一个栈s2用于存放排好序的数；每次从s1 pop出一个数临时存储；若他比s2的top小，则s1.push(s2.pop());然后插入tmp;
 *       直到s1为空。
 */
#include <iostream>
#include <stack>

using namespace std;

stack<int> sortStack(stack<int> &st) {
  stack<int> res; int tmp = 0;
  while(!st.empty()) {
    tmp = st.top();
    st.pop();
    while(!res.empty() && res.top() > tmp) {
      st.push(res.top());
      res.pop();
    }
    res.push(tmp);
  }
  return res;
}

int main(int argc, char* argv[]) {
  stack<int> st;
  st.push(5);
  st.push(6);
  st.push(1);
  st.push(2);
  st.push(4);
  st.push(3);
  stack<int> res = sortStack(st);
  while(!res.empty()) {
    cout << res.top() << endl;
    res.pop();
  }
  return 0;
}
