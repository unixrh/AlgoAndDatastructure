#include "../common/utils.h"

void getSumPath(TreeNode* root, vector<int> &cur, vector<vector<int> > &res, int sum) {
  if(!root) return;
  cur.push_back(root->val);
  sum = sum - root->val;
  if(sum == 0 && !root->left && !root->right)
    res.push_back(cur);
  getSumPath(root->left, cur, res, sum);
  getSumPath(root->right, cur, res, sum);
  cur.pop_back();
}

int main(int argc, char* argv[]) {
  int num = atoi(argv[1]);
  int sum = atoi(argv[2]);
  TreeNode* root = CommonUtils::buildTree(1, num);
  cout << "---" << endl;
  CommonUtils::printTreeByLayer(root);
  cout << "---" << endl;
  vector<int> cur;
  vector<vector<int> > res;
  getSumPath(root, cur, res, sum);
  for(auto item : res) {
    for(auto node : item) {
      cout << node << " ";
    }
    cout << endl;
  }
  return 0;
}
