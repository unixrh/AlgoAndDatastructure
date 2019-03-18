/* 题目：编写一个方法，将字符串中的空格全部替换为“%20” 
 * 解法：计算出新字符串的总长度，然后从后面开始替换
 */
#include <iostream>

using namespace std;

void ReplaceBlank(char* s, int len) {
  int i = 0, num_of_blank = 0;
  while(s[i] != '\0') {
    if(s[i++] == ' ') {
      num_of_blank++;
    }
  }
  int new_len = 2 * num_of_blank + len;
  int j = len - 1, k = new_len - 1;
  while(j >= 0) {
    if(s[j] != ' ') {
      s[k--] = s[j--]; 
    } else {
      j--;
      s[k--] = '0';
      s[k--] = '2';
      s[k--] = '%';
    }
  }
}

int main(int argc, char* argv[]) {
  string tmp;
  getline(cin, tmp);
  int len = tmp.size();
  char s[len+1];
  strcpy(s, tmp.c_str());
  ReplaceBlank(s, len);
  cout << s << endl;
  return 0;
}
