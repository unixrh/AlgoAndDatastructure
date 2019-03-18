/* 题目：给定字符串 str1, str2， 试着找出str1中包含str2所有字符的最短子串
 * 解法：将str2中的所有字符出现的子树放到map<char, int> 中， 使用left，right两个游标，
 *       每次right右移试着消耗出现过的字符(map.size())，如果消耗光了，则表示找到一个子串了，
 *       这时开始右移left，每次都增加“待消耗”，若某个字符被增加到超过0，表示又有需要被消耗了。
 *       每次右移left，都可以得到更小的子串。
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

string getMin(const string &str1, const string &str2) {
  string res = "";
  if(str1.size() <= 0 || str2.size() <= 0) {
    return res;
  }

  map<char, int> map2;
  for(auto item : str2) {
      map2[item] += 1;
  }
  int left = 0, right = 0, count = map2.size();
  while(right < str1.size()) {
    char c = str1[right];
    if(map2.find(c) != map2.end()) {
      map2[c] -= 1;
      if(map2[c] == 0)
        count--;
    }
    right++;

    while(count == 0) {
      if(res.size() == 0 || right-left < res.size())
        res = str1.substr(left, right-left);
      char c = str1[left];
      if(map2.find(c) != map2.end()) {
        map2[c] += 1;
        if(map2[c] > 0)
        count++;
      }
      left++;
    } 
  }
  return res;
}

int main(int argc, char* argv[]) {
  if(argc < 3) {
    cout << "usage: " << argv[0] << " str1 str2" << endl;
    exit(1);
  }

  cout << getMin(argv[1], argv[2]) << endl;
  return 0;
}
