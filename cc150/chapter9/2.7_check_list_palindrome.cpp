#include <iostream>
#include "../chapter8/node_struct.h"

using namespace std;

Node<int>* insertBefor(Node<int>* head, int n) {
  Node<int>* s = new Node<int>(n);
  s->next = head;
  return s;
}

bool checkListPalindrome(Node<int>* head) {
  Node<int> *slow = head, *fast = head;
  Node<int> *l1 = NULL;
  while(slow && fast && fast->next) {
    l1 = insertBefor(l1, slow->val);
    slow = slow->next;
    fast = fast->next->next;
  }
  // 偶数个
  if(!fast) {
  } else { // 奇数个
    slow = slow->next;
  }

  while(slow) {
    if(l1->val != slow->val) {
      return false;
    }
    slow = slow->next;
    l1 = l1->next;
  }
  return true;
}

int main(int argc, char* argv[]) {
  Linked_list<int> l1;
  for(int i = 0; i < 5; i++) {
    l1.append(i);
  }
  for(int i = 4; i >= 0; i--) {
    l1.append(i);
  }
  l1.append(3);
  l1.printList();
  if(checkListPalindrome(l1.head))
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
