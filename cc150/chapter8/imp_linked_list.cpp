#include "node_struct.h"
int main() {
  Linked_list l;
  l.append(1);
  l.append(2);
  l.append(3);
  l.printList();
  l.del(2);
  l.printList();
  return 0;
}
