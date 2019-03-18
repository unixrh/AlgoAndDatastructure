/* 题目：删除一个无序链表中重复出现的元素
 * 解法：使用stl的map吧。。。
 */
#include <iostream>
#include <list>
#include <map>

using namespace std;

void removeDup(list<int> &l) {
  map<int, int> m;
  for(auto it = l.begin(); it != l.end(); it++)
    if(m[*it] == 1) 
      l.erase(it);
    else
      m[*it] = 1;
}

void printList(list<int> l) {
  for(auto item : l){
    cout << item << endl;
  }
}

int main() {
  list<int> l{1,2,3,4,3,5,6,6,7,2,9};
  printList(l);
  removeDup(l);
  printList(l);
  return 0;
}
