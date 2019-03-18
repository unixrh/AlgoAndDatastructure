/* 题目：两个链表，每个节点都存着数位，个位在前，做加法
 * 解法：由递归法和非递归法
 */
#include <iostream>
#include "../chapter8/node_struct.h"

using namespace std;

/* 
 * 若个位在最后。则需要这样做：
 * 1、先将较短的链表前面插入足够的0；
 * 2、递归地做加法并带上进位；
 * 3、每个结果都插入链表头部；
 */

void add1(Linked_list<int> &l1, Linked_list<int> l2) {
  Node<int>* head1 = new Node<int>(0);
  Node<int>* head = head1; 
  int carry = 0;
  while(l1.head != NULL && l2.head != NULL) {
    int sum = l1.head->val + l2.head->val + carry;
    carry = sum / 10;
    Node<int>* tmp = new Node<int>(sum % 10);
    head->next = tmp;
    head = tmp;
    l1.head = l1.head->next;
    l2.head = l2.head->next;
  }
  while(l1.head) {
    int sum = l1.head->val + carry;
    carry = sum / 10;
    Node<int>* tmp = new Node<int>(sum % 10);
    head->next = tmp;
    head = tmp;
    l1.head = l1.head->next;
  }
  while(l2.head) {
    int sum = l2.head->val + carry;
    carry = sum / 10;
    Node<int>* tmp = new Node<int>(sum % 10);
    head->next = tmp;
    head = tmp;
    l2.head = l2.head->next;
  }
  if(carry) {
    head->next = new Node<int>(1);
  }
  l1.head = head1->next;
}

Node<int>* add1_recursive(Node<int>* l1, Node<int>* l2, int carry) {
  if(!l1 && !l2 && !carry) {
    return NULL;
  }
  Node<int> *res = new Node<int>(0);
  int value = carry;
  if(l1){
    value += l1->val;
    l1 = l1->next;
  }
  if(l2){
    value += l2->val;
    l2 = l2->next;
  }
  res->val = value % 10;
  cout << value << endl;
  if(l1)
    cout << l1->val << endl;
  if(l2)
    cout << l2->val << endl;
  cout << "-----" << endl;
  Node<int> *tmp = add1_recursive(l1, l2, value / 10);
  res->next = tmp;
  return res;
}

int main(int argc, char* argv[]) {
  Linked_list<int> l1;
  l1.append(6);
  l1.append(1);
  l1.append(7);
  Linked_list<int> l2;
  l2.append(2);
  l2.append(9);
  l2.append(5);
  l1.printList();
  l2.printList();
  // add1(l1, l2);
  l1.head = add1_recursive(l1.head, l2.head, 0);
  l1.printList();
}
