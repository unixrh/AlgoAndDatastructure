#include "../common/utils.h"

void serialize(TreeNode* root, string& res) {
  if(root) {
    res += to_string(root->val) + "!";
    serialize(root->left, res);
    serialize(root->right, res);
  } else {
    res += "#!";
  }
}

TreeNode* deserialize(const string& str, size_t cur) {
  TreeNode* root = NULL;
  while(cur < str.size()) {
    int i = cur;
    while(i < str.size() && str[i] != '!') {
      i++;
    }
    cout << cur << i << endl;
    cout << str.substr(cur, i-cur) << endl; 
    if(i < str.size()) {
      if(str.substr(cur, i-cur) == "#") {
        return NULL;
      } else {
        int val = atoi(str.substr(cur, i-cur).c_str());
        if(cur == 0) {
          root = new TreeNode(val); 
        } else {
          root = new TreeNode(val);
          root->left = deserialize(str, cur+1);
          if(root->left == NULL)
            return new TreeNode(val);
          root->right = deserialize(str, cur+1);
          if(root->right == NULL)
            return new TreeNode(val);
        }
      }
    }
    cur = i + 1;
  }
  return root;
}

int main() {
  TreeNode* root = CommonUtils::buildTree(1, 15);
  CommonUtils::printTreePreorder(root);
  cout << endl;
  string res = "";
  serialize(root, res);
  cout << res << endl;
  cout << res.size() << endl;
  TreeNode* x = deserialize(res, 0);
  CommonUtils::printTreePreorder(x);
  return 0;
}
