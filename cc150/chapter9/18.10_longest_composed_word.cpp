/* 题目：给一本字典，找出其中长度最长的单词，同时该单词需由其他单词组成
 * 解法：将单词拆为两部分,递归地查找,同时将各个结果更新到字典里并且置为不在字典
 */
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool canBeBuilt(string str, bool isOriginal, map<string, bool> dict) {
  if(dict.find(str) != dict.end() && !isOriginal) {
    return dict[str];
  }
  for(int i = 1; i < str.size() - 1; i++) {
    string left = str.substr(0, i);
    string right = str.substr(i);
    cout << left << endl;
    if(dict[left] && canBeBuilt(right, false, dict))
      return true;
  }
  dict[str] = false;
  return false;
}

string longestComposedWord(string str, map<string, bool> dict) {
  string res = "";
  int start = 0, end = 0, j = 0;
  char delimeter = ' ';
  for(int i = 1; i < str.size(); i++) {
    j = i-1;
    int len = 1;
    while(i < str.size() && str[i++] != delimeter) {
      len++;
    }
    string tmp = str.substr(j, len); 
    if(i-j > end-start && dict[tmp] == true && canBeBuilt(tmp, true, dict)) {
      start = j;
      end = i;
    }
  }
  res = str.substr(start, end - start);
  return res;
}

int main(int argc, char* argv[]) {
  vector<string> dict_vec{"we", "are", "love", "you", "weareloveyou", "love you", "weare", "wed", "were", "wear", "weell", "well", "ll", "ee", "u", "yo", "welt"};
  map<string, bool> dict;
  for(auto item:dict_vec)
    dict[item] = true;
  string input;
  getline(cin, input);
  cout << longestComposedWord(input, dict) << endl;
  return 0;
}
