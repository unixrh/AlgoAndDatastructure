/* 求一串字符的排列组合
 * 解法：将字符串分为两部分，第一部分为第1个字符，第二部分为剩下的字符
 *       依次将第1个字符与第二部分的各个元素进行交换
 *       递归
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void perm1(string &s, int step, vector<string> &res) {
  if(step == s.size()) {
    res.push_back(s);
    return;
  }
  for(int i = step; i < s.size(); i++) {
    char tmp = s[i];
    s[i] = s[0];
    s[0] = tmp;
    perm1(s, step+1, res);
    tmp = s[i];
    s[i] = s[0];
    s[0] = tmp;
  }
}

void perm(char* s, char* p, vector<string> &res) {
  if(*p == '\0'){
    res.push_back(string(s));
  } else {
    for(char* pch = p; *pch != '\0'; pch++) {
      char tmp = *pch;
      *pch = *p;
      *p = tmp;
      perm(s, p+1, res);
      tmp = *pch;
      *pch = *p;
      *p = tmp;
    }
  }
}

void perm(char* s, int l, int r) {
  if(l == r)
    cout << s << endl;
  else {
    for(int i = l; i <= r; i++) {
      swap(s[l], s[i]);
      perm(s, l+1, r);
      swap(s[l], s[i]);
    }
  }
}

int main(int argc, char* argv[]) {
  char* s = argv[1];
  string t = string(s);
  vector<string> res;
  // perm1(t, 0, res);
  perm(s, s, res);
  // perm(s, 0, strlen(s) - 1);
  for(auto item : res) {
    cout << item << endl;
  }
  return 0;
}
