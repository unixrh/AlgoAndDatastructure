#include <iostream>
using namespace std;
template <typename T>
class Node {
  public:
  T val;
  Node *next;
  Node() {}
  Node(T t) {
    val = t;
    next = NULL;
  }
};

template <typename T>
class Linked_list {
  public:
  Node<T> *head = NULL;
  Node<T> *tail = NULL;
  void append(T d) {
    if(head == NULL) {
      head = new Node<T>(d);
      tail = head;
      return;
    } 
    Node<T> *tmp = new Node<T>(d);
    tail->next = tmp;
    tail = tmp;
  }

  void del(T d) {
    Node<T> *tmp = head;
    if(head->val == d)
      head = head->next;
    while(tmp->next != NULL) {
      if(tmp->next->val == d) {
        tmp->next = tmp->next->next;
      }
      tmp = tmp->next;
    }
  }

  Node<T> *getNodeByVal(T d) {
    Node<T> *tmp = head;
    while(tmp != NULL && tmp->val != d) {
      tmp = tmp->next;
    }
    return tmp;
  }

  void reverse1() {
    Node<T> *p = NULL, *c = head, *n = NULL;
    while(c) {
      n = c->next;
      c->next = p;
      p = c;
      c = n;
    }
    head = p;
  }

  void reverse() {
    if(!head || !head->next)
      return;

    Node<T> *p = NULL, *c = head, *n = head->next;
    while(n) {
      Node<T> *tmp = n->next;
      c->next = p;
      p = c;
      n->next = c;
      c = n;
      n = tmp;
    }
    head = c;
  }

  void printList() {
    Node<T> *tmp = head;
    while(tmp != NULL) {
      cout << tmp->val << "->";
      tmp = tmp->next;
    }
    cout << "NULL " << endl;
  }
};
