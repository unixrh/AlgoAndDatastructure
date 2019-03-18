#include "../cc150/chapter8/node_struct.h"
#include <iostream>

using namespace std;

void reverse(Node<int> *head) {
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "usage: " << argv[0] << " num" << endl;
    exit(1);
  }
  Linked_list<int> l;
  for(int i = 0; i < atoi(argv[1]); i++) {
    l.append(i);
  }
  l.printList();
  l.reverse1();
  l.printList();
  return 0;
}
