/* 题目：使用两个栈来实现队列
 * 解法：一个栈正常存储压入的数据，另一个存反向的数据；为了减少反向操作，只有当必要时才反向
 */

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
  public: 
    MyQueue(){}
    void enqueue(int x) {
      stack1.push(x);
    }
    int dequeue() {
      int res = -1;
      if(stack2.empty()) {
        while(!stack1.empty()) {
          stack2.push(stack1.top());
          stack1.pop();
        }
      }
      if(!stack2.empty()) {
        res = stack2.top();
        stack2.pop();
      }
      return res;
    }
  private:
    stack<int> stack1, stack2;
};

int main(int argc, char* argv[]) {
  MyQueue queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.enqueue(4);
  queue.enqueue(5);
  cout << queue.dequeue() << endl;
  cout << queue.dequeue() << endl;
  queue.enqueue(6);
  queue.enqueue(7);
  cout << queue.dequeue() << endl;
  cout << queue.dequeue() << endl;
  cout << queue.dequeue() << endl;
  cout << queue.dequeue() << endl;
  cout << queue.dequeue() << endl;
  cout << queue.dequeue() << endl;
}
