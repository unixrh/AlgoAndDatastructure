#include "../common/utils.h"

void mirror(TreeNode* root) {
  if(!root || (!root->left && !root->right)) return;
  TreeNode* tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  mirror(root->left);
  mirror(root->right);
}

int main(int argc, char* argv[]) {
  int num = atoi(argv[1]);
  TreeNode* root = CommonUtils::buildTree(0, num);
  cout << "res root: " << root << endl;
  CommonUtils::printTreeByLayer(root);
  cout << "---" << endl;
  mirror(root);
  CommonUtils::printTreeByLayer(root);
  cout << "---" << endl;
  return 0;
}
