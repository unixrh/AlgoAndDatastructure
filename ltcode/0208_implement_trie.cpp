#include <iostream>

using namespace std;

typedef struct trieNode {
  bool m_isWord;
  trieNode* m_ch[26];
  trieNode() {
    for(int i = 0; i < 26; i++) {
      m_ch[i] = NULL;
    }
    m_isWord = false;
  }
} TrieNode;

class Trie {
public:
  TrieNode* root;

  Trie() {
    root = new TrieNode();
  }

  void insert(string word) {
    TrieNode* p = root;
    int i = 0, n = word.size();
    while(i < n) {
      int index = word[i] - 'a';
      if(p->m_ch[index] == NULL)
        p->m_ch[index] = new TrieNode();
      p = p->m_ch[index];
      if(i == n -1) {
        p->m_isWord = true;
      }
      i++;
    }
  }

  bool search(string word) {
    TrieNode* p = root;
    int i = 0, n = word.size();
    while(i < n && p != NULL) {
      int index = word[i] - 'a';
      if(p->m_ch[index] == NULL)
        return false;
      p = p->m_ch[index];
      i++;
    }
    return p && p->m_isWord;
  }

  bool startWith(string prefix) {
    TrieNode* p = root;
    int i = 0, n = prefix.size();
    while(i < n && p != NULL) {
      int index = prefix[i] - 'a';
      if(p->m_ch[index] == NULL)
        return false;
      p = p->m_ch[index];
      i++;
    }
    return p && p->m_isWord;
  }
};

int main(int argc, char* argv[]) {
  Trie a;
  a.insert("apple");
  a.insert("app");
  if(a.search("app"))
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
