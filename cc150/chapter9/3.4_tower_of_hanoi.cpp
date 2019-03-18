/* 经典汉诺塔问题
 */
#include <iostream>

using namespace std;

void hanoi(int n, char from, char buffer, char to) {
  if(n == 0) {
    return;
  }

  hanoi(n-1, from, to, buffer);
  cout << "move disk " << n << " from " << from << " to " << to << endl;
  hanoi(n-1, buffer, from, to);
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << argv[0] << " num" << endl;
    exit(1);
  }

  hanoi(atoi(argv[1]), 'A', 'B', 'C');
  return 0;
}
