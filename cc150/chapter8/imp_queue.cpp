#include <iostream>
#include "node_struct.h"
using namespace std;
class Queue{
  public:
    Node<int> *first, *last;
  void enqueue(int d) {
    if(first == NULL) {
      last = new Node<int>(d);
      first = last;
    } else {
      last->next = new Node<int>(d);
      last = last->next;
    }
  }

  int dequeue() {
    int res = -1;
    if(first != NULL){
      res = first->val;
      first = first->next;
    }
    return res;
  }

  void printQueue() {
    Node<int> *tmp = first;
    while(tmp != NULL) {
      cout << tmp->val << endl;
      tmp = tmp->next;
    }
    cout << "sfas" << endl;
  }
};

int main() {
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);
  q.printQueue();
  cout << "xx" << q.dequeue() << endl;
  cout << "xx" << q.dequeue() << endl;
  q.enqueue(7);
  q.printQueue();
  return 0;
}
