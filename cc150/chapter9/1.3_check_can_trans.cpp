/* 题目：给定两个字符串，确定其中一个能否重新排列变成另一个
 * 解答：我用了两个数组，不够好，实际上只要用一个数组即可。
 * */
#include <iostream>
using namespace std;

bool canTransV2(string s1, string s2) {
  if(s1.size() != s2.size()) 
    return false;
  int a1[256] = {0};
  int i = 0;
  while (i < s1.size()) {
    a1[s1[i++] - '0']++;
  }
  i--;
  while(i >= 0) {
    if(--a1[s2[i--] - '0'] < 0) 
      return false;
  }
  return true;
}

bool canTrans(string s1, string s2) {
  if(s1.size() != s2.size()) 
    return false;
  int a1[256] = {0};
  int a2[256] = {0};
  int i = 0;
  while(i < s1.size()) {
    a1[s1[i++] - '0']++;
  }
  while(i >= 0) {
    a2[s2[i--] - '0']++;
  }
  while(i < 256) {
    if(a2[i] != a1[i]) 
      return false;
    i++;
  }
  return true;
}

int main(int argc, char* argv[]) {
  if(argc < 3) {
    cout << "pls input 2 words" << endl;
    exit(1);
  }
  if(canTransV2(argv[1], argv[2])) {
    cout << argv[1] << " can be transformed to " << argv[2] << endl;
  } else {
    cout << argv[1] << " can not be transformed to " << argv[2] << endl;
  }
  return 0;
}
