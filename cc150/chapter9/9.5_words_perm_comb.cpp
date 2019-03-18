/* 题目：编写一个方法，确定某个字符串的所有排列组合。
 *
 * 思路：1、只有空字符时，加入一个字符，则新增为拼接;
 *       2、对于以上集合，再加入时，则新增为在原有的基础上拼接；
 *       3、注意这里的拼接是将新字符插入旧集合每个元素的每个位置；
 *       4、新集合 = 新增集合 + 旧集合；
 *       5、重复以上步骤。
 * */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<string> v) {
  for(auto i : v) {
    cout << i << endl;
  }
}

vector<string> getCombination(string s) {
  static vector<string> tmp;
  if(s.size() == 0) {
    tmp.push_back("");
    return tmp;
  }
  char first = s[0];
  // cout << "first: " << first << endl;
  string remainer = s.substr(1);
  vector<string> words = getCombination(remainer);
  // printVector(words);
  for(auto word : words) {
    // cout << "Word: " << word << endl;
    for(int i = 0; i <= word.size(); i++) {
      string newWord = word.substr(0, i) + first + word.substr(i);
      // cout << "newWord: " << newWord << endl;
      tmp.push_back(newWord);
    }
  }
  return tmp;
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    // cout << "pls input a word" << endl;
    exit(1);
  }
  string s = argv[1];
  // cout << "input word is: " << s << endl;
  vector<string> res;
  res = getCombination(s);
  // cout << "result: " << endl;
  printVector(res);
  return 0;
}
