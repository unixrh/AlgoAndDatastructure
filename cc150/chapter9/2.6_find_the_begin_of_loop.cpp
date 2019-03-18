/* 题目：一个有环的单向链表，找出环的起点位置
 * 解法：设置一快一慢两个指针，假设起点距离头部为k,则当慢的到达起点时，快的已经入环走了k步，另s=k%loopsize, 则当前快的领先慢的s步，也就是还要loopsize-s步即可追上慢的，每次快的会靠近慢的一步，所以慢的再走loopsize-s步之后两个重合，此时交汇点领先环起点loopsize-s步，或者说慢的还要走s步才能再次回到环起点。然后s=k%looopsize;即k=s+n*loopsize;所以这时再从头部出发，则最终会和慢的在环起点遇上。
 */
#include <iostream>
#include "../chapter8/node_struct.h"

using namespace std;

Node<int>* find(Node<int>* head) {
  Node<int> *slow = head->next, *fast = head->next->next;
  while(slow != fast) {
    slow = slow->next;
    fast = fast->next->next;
  }
  fast = head;
  while(fast != slow) {
    slow = slow->next;
    fast = fast->next;
  }
  return fast;
}

int main(int argc, char* argv[]) {
  if(argc < 2) exit(-1);
  Linked_list<int> l1;
  for(int i = 0; i < 30; i++) {
    l1.append(i);
  }
  l1.printList();
  Node<int>* target = l1.getNodeByVal(atoi(argv[1]));
  l1.tail->next = target;
  Node<int>* res = find(l1.head);
  cout << "------" << endl;
  cout << res->val << endl;
  return 0;
}
