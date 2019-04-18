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
  if(cur == str.size()) {
    return NULL;
  } else {
    int i = cur;
    while(i < str.size() && str[i] != '!') {
      i++;
    }
    if(str.substr(cur, i - cur) == '#') {
      return NULL;
    } else {
      TreeNode *root = new TreeNode(atoi(str.substr(cur, i - cur)))
      root->left = deserialize(str, i)
    }
  }
}

int main() {
  TreeNode* root = CommonUtils::buildTree(1, 15);
  CommonUtils::printTreeByLayer(root);
  string res = "";
  serialize(root, res);
  cout << res << endl;
  TreeNode* des = deserialize(res, 0);
  CommonUtils::printTreeByLayer(des);
  return 0;
}