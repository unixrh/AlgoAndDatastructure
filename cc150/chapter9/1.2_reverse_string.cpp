/* 题目：翻转一个\0结尾的字符串
 * */
#include <iostream>
using namespace std;

void reverse(char* s) {
  int i = 0;
  while(s[i] != '\0') {
    i++;
  }
  i--;
  int j = 0;
  while (j < i) {
    char tmp = s[j];
    s[j] = s[i];
    s[i] = tmp;
    i--;
    j++;
  }
}
int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "pls input" << endl;
    exit(1);
  }
  cout << argv[1] << endl;
  char* s = argv[1];
  reverse(s);
  cout << s << endl;
  return 0;
}
