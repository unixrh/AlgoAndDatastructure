/* 题目：实现树的序列化与反序列化
 * 思路：每个元素用‘!’隔开，NULL用"#"替代
 *       使用前序遍历生成字符串
 *       反序列化时，将字符串先分割为数组
 */
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

TreeNode* deserialize(const vector<string>& vec, size_t &cur) {
  if(cur >= vec.size() || vec[cur] == "#") {
    cur += 1;
    return NULL;
  }
  TreeNode* root = new TreeNode(atoi(vec[cur].c_str()));
  cur += 1;
  root->left = deserialize(vec, cur);
  root->right = deserialize(vec, cur);
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
  int cur = 0;
  vector<string> vec;
  // res = "12!#!3!#!#!";
  while(cur < res.size()){
    int i = cur;
    while(i < res.size() && res[i] != '!') {
      i++;
    }
    vec.push_back(res.substr(cur, i-cur));
    cur = i + 1;
  }
  size_t a = 0;
  TreeNode* x = deserialize(vec, a);
  CommonUtils::printTreePreorder(x);
  CommonUtils::printTreeByLayer(x);
  return 0;
}
