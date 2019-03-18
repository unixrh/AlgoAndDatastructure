/* 题目：编写一个方法，返回集合的所有子集
 * 解法：1、可以看成拼接；2、可以看成0，1，0，1，1.。。的组合，然后遍历之
 */
#include <iostream>
#include <vector>

using namespace std;

void combine(const string raw, vector<string>& res, int index) {
  if(index < 0)
    return;
  vector<string> tmp(res.begin(), res.end());
  for(auto item : tmp) {
    string t = item + raw[index];
    res.push_back(t);
  }
  combine(raw, res, index-1);
}

int main() {
  string raw = "abc";
  vector<string> res = {""};
  combine(raw, res, raw.size()-1);
  for(auto item:res) {
    cout << item << endl;
  }
  return 0;
}
