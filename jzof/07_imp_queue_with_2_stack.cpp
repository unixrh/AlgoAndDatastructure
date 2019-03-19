/* 题目：使用两个栈实现队列
 * 解法：一个用来存，另一个用来读和出队，当后者为空时，将前者倒入后者
 */
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
  private:
    stack<int> st_in, st_out;
  public:
    MyQueue(){}
    ~MyQueue(){}
    void enque(int x) {
      st_in.push(x);
    }
    int deque() {
      if(st_out.empty() && st_in.empty()) {
        return -1;
      } else if(st_out.empty()) {
        while(!st_in.empty()) {
          st_out.push(st_in.top());
          st_in.pop();
        }
      }
      if(st_out.empty()) {
        return -1;
      }
      int res = st_out.top();
      st_out.pop();
      return res;
    }
    bool empty() {
      return st_in.empty() && st_out.empty();
    }
    int front() {
      if(st_out.empty() && st_in.empty()) {
        cout << "front empty" << endl;
        return -1;
      } else {
          cout << "st_in.top(): " << st_in.top() << endl;
        while(!st_in.empty()) {
          cout << "st_in.top(): " << st_in.top() << endl;
          st_out.push(st_in.top());
          st_in.pop();
        }
      }
      if(st_out.empty()) {
        cout << "1front empty" << endl;
        return -1;
      }
      return st_out.top();
    }
};

int main() {
  MyQueue m;
  m.enque(1);
  m.enque(2);
  m.enque(3);
  cout << m.deque() << endl;
  m.enque(4);
  m.enque(5);
  cout << m.deque() << endl;
  m.enque(6);
  m.enque(7);
  cout << "-------" << endl;
  while(!m.empty())
    cout << m.deque() << endl;
  return 0;
}
