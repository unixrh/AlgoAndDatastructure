/* 使用两个队列实现栈
 * 这里需要考虑的是，实际情况能够容忍push耗时还是pop耗时，因为数据转移是O(N)的复杂度
 */
#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class MyStack {
  public:
    MyStack() {
    }

    void push(T x) {
      // 将q2作为输出队列，因此将它清空然后放入最新数据
      swap(q1, q2); // 队列的底层实现是list或者deque,因此swap过程是O(1),这样写代码简洁一些
      q2.push(x);

      while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
      }
    }

    T pop() {
      if(q2.empty()) {
        return -1;
      }
      T res = q2.front();
      q2.pop();
      return res;
    }

  private:
    queue<T> q1, q2;
    void swap(queue<T> &q1, queue<T> &q2) {
      if(q1.empty()) {
        queue<T> tmp(q1);
        q1 = q2;
        q2 = tmp;
      }
    }
};

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << argv[0] << " num" << endl;
    exit(1);
  }
  MyStack<int> st;
  for(int i = 0; i < atoi(argv[1]); i++) {
    st.push(i);
  }

  for(int i = 0; i < atoi(argv[1]); i++) {
    cout << st.pop() << endl;
  }

  MyStack<char> st1;
  for(int i = 0; i < atoi(argv[1]); i++) {
    st1.push(i+'A');
  }

  for(int i = 0; i < atoi(argv[1]); i++) {
    cout << st1.pop() << endl;
  }
  return 0;
}
