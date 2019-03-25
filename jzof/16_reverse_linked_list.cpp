/* 翻转链表
 */
#include "../common/utils.h"

ListNode* reverse(ListNode* head) {
  if(!head) return head;
  ListNode *cur = head, *next = head->next;
  ListNode *prev = NULL;
  while(cur) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "usage: " << argv[0] << " num" << endl;
    exit(1);
  }
  ListNode *head = new ListNode(-1);
  ListNode *tmp = head;
  int num = atoi(argv[1]);
  for(int i = 0; i <= num; i++) {
    ListNode *n = new ListNode(i);
    tmp->next = n;
    tmp = tmp->next;
  }
  CommonUtils::printList(head);
  CommonUtils::printList(reverse(head));
  delete head;
}
