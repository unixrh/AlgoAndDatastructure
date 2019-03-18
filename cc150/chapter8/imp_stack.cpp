#include <iostream>
#include "node_struct.h"

using namespace std;
class Stack {
  public:
  Node<int> *top = NULL;
  int pop() {
    int res = -1;
    if(top != NULL) {
      res = top->val;
      top = top->next;
    } 
    return res;
  }

  void push(int d) {
    Node<int> *t = new Node<int>(d);
    t->next = top;
    top = t;
  }

  int peek() {
    return top->val;
  }

  void printStack() {
    Node<int> *tmp = top;
    while(tmp != NULL) {
      cout << tmp->val << endl;
      tmp = tmp->next;
    }
  }
};

int main() {
  Stack s;
  cout << s.pop() << endl;
  s.push(1);
  s.push(2);
  s.push(3);
  cout << s.peek() << endl;
  s.printStack();
  cout << s.pop() << endl;
  cout << s.pop() << endl;
  s.printStack();
  return 0;
}
