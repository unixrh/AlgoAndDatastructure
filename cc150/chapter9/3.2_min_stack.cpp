/* 我的代码实现是令stack2每次都同步地进行pop和push这种做法比较浪费空间；
 * 如果可以保证栈的元素各异，则可以令第二个栈保存较少的数据；
 * 具体而言：push时，仅当入栈值小于stack2.top()时才入stack2;
 *           pop时，仅当出栈的值等于stack2.top()时才stack2.pop();
 */
#include <iostream>

#define STACK_SIZE 100
using namespace std;
class MinStack {

  int _top = 0;;
  int _min_top = 0;;
  int _stack[STACK_SIZE];
  int _min_stack[STACK_SIZE] = {10000};

  public:
  MinStack(){}
  int pop() {
    if(_top == 0)
      return -1;
    int res = _stack[_top]; 
    _top--;
    _min_top--;
    return res;
  }

  void push(int x) {
    assert(_top < STACK_SIZE - 1);
    _top++;
    _stack[_top] = x;
    _min_top++;
    _min_stack[_min_top] = std::min(x, _min_stack[_min_top - 1]);
  }

  int min() {
    return _min_stack[_min_top];
  }
};

int main(int argc, char* argv[]) {
  MinStack s;
  s.push(4);
  s.push(3);
  cout << s.min() << endl;
  s.pop();
  cout << s.min() << endl;
  s.push(6);
  s.push(7);
  s.push(2);
  cout << s.min() << endl;
  s.push(1);
  cout << s.min() << endl;
  s.push(3);
  cout << s.min() << endl;
}
