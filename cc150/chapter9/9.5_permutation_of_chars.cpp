#include <iostream>
#include <vector>

using namespace std;

string insert(string s, int i, char c) {
  return s.substr(0, i) + c + s.substr(i);
}

void perm(const string raw, vector<string> &res, int n) {
  if(n < 0) {
    return;
  }

  vector<string> tmp = res;

  for(auto item : tmp) {
    for(int i = 0; i <= item.size(); i++) {
      string x = insert(item , i, raw[n]);
      res.push_back(x);
    }
  }

  perm(raw, res, n-1);
}

int main() {
  string raw = "abcd";
  vector<string> res{""};
  perm(raw, res, raw.size() - 1);
  for(auto item : res) {
    cout << item << endl;
  }
  return 0;
}
