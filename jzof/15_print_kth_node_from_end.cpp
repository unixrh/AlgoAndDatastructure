/* 输出链表的倒数第K个节点
 */
#include "../common/utils.h"

ListNode* getKth(ListNode *head, int k) {
  if(!head) return NULL;
  ListNode *fast = head, *slow = head;
  while(fast && k > 0) {
    fast = fast->next;
    k--;
  }
  if(k > 0)
    return NULL;
  while(fast) {
    fast = fast->next;
    slow = slow->next;
  }
  return slow;
}


int main(int argc, char* argv[]) {
  if(argc < 3) {
    cout << "usage: " << argv[0] << " num k" << endl;
    exit(1);
  }
  ListNode *head = new ListNode(-1);
  ListNode *tmp = head;
  int num = atoi(argv[1]);
  int k = atoi(argv[2]);
  for(int i = 0; i <= num; i++) {
    ListNode *n = new ListNode(i);
    tmp->next = n;
    tmp = tmp->next;
  }
  CommonUtils::printList(head);
  ListNode* res = getKth(head, k);
  if(res)
    cout << res->val << endl; 
  else
    cout << "invalid" << endl;
  delete head;
}
