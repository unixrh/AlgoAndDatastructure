/* 题目：打印 0 到 n 位数的所有数字
 * 解法：当做排列组合来处理，设定一个n+1长度的字符数组，然后在低位从0开始填，高位渐渐补齐，直到补到n位为止
 */
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

void printNum(char *number) {
  int len = strlen(number);
  bool zero = true;
  int i = 0;
  for(i = 0; i < len-1; i++) {
    if(zero && number[i] != '0') {
      zero = false;
    }
    if(!zero)
      printf("%s\n", number+i);
  }
}

void printString(char *number, int n, int index) {
  if(n == index+1) {
    printNum(number);
    return;
  }
  for(int i = 0; i < 10; i++) {
    number[index + 1] = '0' + i;
    printString(number, n, index+1);
  }
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "usage: " << argv[0] << " num" << endl;
    exit(1);
  }
  int n = atoi(argv[1]);
  char* number = new char(n+1);
  number[n] = '\0';
  for(int i = 0; i < 10; i++) {
    number[0] = i+'0';
    printString(number, n, 0);
  }
  return 0;
}
