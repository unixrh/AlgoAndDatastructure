/* 题目：判断一个字符串能否由另一个字符串旋转而来
 * 解法：str1 + str1 是否包含str2
 */
#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string haystack, string needle) {
  int l = needle.size();
  for(int i = 0; i < haystack.size() - l; i++) {
    if(haystack.substr(i, l) == needle)
      return true;
  }
  return false;
}

bool canBeRotated(string str1, string str2) {
  return isSubstring(str2 + str2, str1);
}

int main(int argc, char* argv[]) {
  if(argc < 3) exit(-1);
  if(canBeRotated(argv[1], argv[2]))
    cout << "yes" << endl;
  else
    cout << "no" <<endl;
  return 0;
}
