/* 合并排序的链表，注意一个承载链表到头但是另一个链表还没结束时应直接append
 * 递归的方式很简洁清晰
 */
#include "../common/utils.h"

ListNode* merge(ListNode* head1, ListNode* head2) {
  if(!head1)
    return head2;
  if(!head2)
    return head1;
  if(head1->val > head2->val) {
    swap(head1, head2);
  }
  ListNode* res = head1;
  ListNode* prev = head1;
  head1 = head1->next;
  while(head1 && head2) {
    if(head1->val > head2->val) {
      ListNode* tmp = head2;
      head2 = head2->next;
      prev->next = tmp; 
      tmp->next = head1;
      prev = prev->next;
    } else {
      head1 = head1->next;
    }
  }
  return res;
}

ListNode* mergeRecursive(ListNode *head1, ListNode* head2){
  if(!head1)
    return head2;
  if(!head2)
    return head1;
  ListNode* dummy = NULL;
  if(head1->val > head2->val) {
    dummy = head2;
    dummy->next = mergeRecursive(head1, head2->next);
  } else {
    dummy = head1;
    dummy->next = mergeRecursive(head1->next, head2);
  }
  return dummy;
}
