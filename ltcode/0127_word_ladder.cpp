// 使用队列实现深度优先搜索
// 使用unordered_set来存储字典，通过其erase和find命令来减小时间的复杂度
// 通过遍历每个字幕的可能性来控制计算规模
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
  public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> dict(wordList.begin(), wordList.end());
      queue<string> q;

      int count = 1;
      q.push(beginWord);
      q.push("###");

      bool push = false;
      while(!q.empty()) {
        string word = q.front();
        cout << word << endl;
        q.pop();
        if(word == endWord) {
          return count;
        }
        if(word == "###") {
          count++;
          if(push) {
            q.push("###");
            push = false;
          }
        }
        for (int j = 0; j < word.size(); j++) {
          char c = word[j];
          for (int k = 0; k < 26; k++) {
            word[j] = 'a' + k;
            if (dict.find(word) != dict.end()) {
              q.push(word);
              dict.erase(word);
              push = true;
            }
          }
          word[j] = c;
        }
      }
      return 0;
    }
};
