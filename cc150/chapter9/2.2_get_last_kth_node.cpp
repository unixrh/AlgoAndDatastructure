/* 题目：找到单向链表的倒数第K个节点
 * 解法：使用快慢指针
 */
#include <iostream>
#include "../chapter8/node_struct.h"

using namespace std;

Node<int>* lastKth(Node<int>* head, int k) {
  Node<int>* slow = head, *fast = head;
  while(k-- > 0 && fast != NULL ) {
    fast = fast->next;
  }
  if(k > 0 && fast == NULL) 
    return NULL;
  while(fast != NULL) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

int main(int argc, char* argv[]) {
  if(argc < 2) 
    exit(-1);
  Linked_list<int> l;
  l.append(1);
  l.append(2);
  l.append(4);
  l.append(5);
  l.append(6);
  l.append(7);
  l.append(8);
  l.printList();
  Node<int>* res = lastKth(l.head, atoi(argv[1]));
  if(res)
    cout <<  res->val << endl;
  else
    cout << "Invalid k!" << endl;
}
