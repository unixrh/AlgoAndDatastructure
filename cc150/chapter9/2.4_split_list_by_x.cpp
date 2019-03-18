/* 题目：利用X将链表分为分成两部分，使得小于X的都在大等于X的前面
 * 解法：使用两个小的链表临时来存
 */
#include <iostream>
#include "../chapter8/node_struct.h"

using namespace std;

void split_x(Linked_list<int> &l, int x) {
  if(!l.head) return;
  Node<int> *smallHead = new Node<int>(0);
  Node<int> *bigHead = new Node<int>(0);
  Node<int> *small = smallHead;
  Node<int> *big = bigHead;
  while(l.head != NULL) {
    Node<int> *tmp = l.head;
    if(l.head->val < x) {
      small->next = tmp;
      small = small->next;
    } else {
      big->next = tmp;
      big = big->next;
    }
    l.head = l.head->next;
  }
  small->next = bigHead->next;
  big->next =  NULL;
  l.head = smallHead->next;
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    exit(-1);
  }
  Linked_list<int> l;
  l.append(21);
  l.append(2);
  l.append(3);
  l.append(14);
  l.append(5);
  l.append(25);
  l.printList();
  split_x(l, atoi(argv[1]));
  cout << "xxx" << endl;
  l.printList();
  return 0;
}
