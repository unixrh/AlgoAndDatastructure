/* 题目：删除单链表中的目标节点
 * 解法：将后面的值赋给目标节点，然后删除后面的节点
 */
#include <iostream>
#include "../common/utils.h"

void deleteNode(ListNode* target) {
  if(!target->next) {
    target = NULL;
  } else {
    ListNode *tmp = target->next;
    target->val = tmp->val;
    target->next = tmp->next;
    delete tmp;
  } 
}

int main(int argc, char* argv[]) {
  if(argc < 3) {
    cout << "usage: " << argv[0] << " num delpos" << endl;
    exit(1);
  }
  ListNode *head = new ListNode(-1);
  ListNode *tmp = head;
  int num = atoi(argv[1]);
  int delpos = atoi(argv[2]);
  ListNode *target = NULL;
  for(int i = 0; i <= num; i++) {
    ListNode *n = new ListNode(i);
    tmp->next = n;
    tmp = tmp->next;
    if(i == delpos)
      target = n; 
  }
  CommonUtils::printList(head);
  deleteNode(target);
  CommonUtils::printList(head);
  delete head;
}
