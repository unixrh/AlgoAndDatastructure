/* 题目：实现一个算法，删除单向链表中的某个节点，假定你只能访问该节点。
 * 解法：将该节点的后一个节点复制给它，然后删除后一个节点即可。
 */
#include <iostream>
#include "../chapter8/node_struct.h"

using namespace std;

void del_node(Node<int>* node) {
   Node<int> *tmp = node->next;
   if(tmp) {
     *node = *tmp;
     delete tmp;
   } else {
     node = tmp;
   }
}

int main(int argc, char* argv[]) {
  Linked_list<int> l;
  l.append(1);
  l.append(2);
  l.append(3);
  l.append(4);
  l.append(5);
  l.printList();
  Node<int> *tmp = l.getNodeByVal(3);
  del_node(tmp);
  l.printList();
  return 0;
}
