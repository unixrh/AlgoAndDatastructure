/* 实现一个栈的集合，但是要在外部看来push和pop方法与一个栈的操作完全一致
 * *******
 * 若要实现popAtIndex(int x)，即实现从某个栈中pop出来。则可以这样做：
 * 比如在2号pop之后，则将3的栈底移动到2的顶部，然后将4的栈底补充给3；这是节约空间的做法。
 */
#include <iostream>
#include <stack>
#include <vector>

#define SINGLE_STACK_SIZE 10

using namespace std;

class SetOfStacks {
  public:
    SetOfStacks(){
      stack<int>* s = new stack<int>;
      setOfStacks.push_back(s);
    }
    void push(int x) {
      stack<int>* last = getLastStack();
      if(last != NULL && last->size() < SINGLE_STACK_SIZE) {
        last->push(x);
      } else {
        stack<int>* tmp = new stack<int>;
        setOfStacks.push_back(tmp);
        tmp->push(x);
      }
    }

    int pop() {
      stack<int>* last = getLastStack();
      if(last->empty()) 
        return -1;
      int res = last->top();
      last->pop();
      if (last->empty() && setOfStacks.size() > 1) {
        setOfStacks.pop_back();
      }
      return res;
    }

  private:
    vector<stack<int> *> setOfStacks;
    stack<int>* getLastStack() {
      stack<int> *last = setOfStacks.back();
      return last;
    }
};

int main(int argc, char* argv[]) {
  SetOfStacks *ss = new SetOfStacks();
  for(int i = 1; i <= atoi(argv[1]); i++) {
    ss->push(i);
  }
  for(int i = 1; i <= atoi(argv[1]); i++) {
    cout << ss->pop() << endl;
  }
  return 0;
}
