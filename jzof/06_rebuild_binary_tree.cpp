/* 题目：给定二叉树的前序和中序，重建整棵树
 * 解法：根据前序找到根，然后在中序将数组分为左右子树，递归
 */
#include <iostream>
#include <vector>
#include "data_struct.h"

using namespace std;
TreeNode* rebuild(vector<int> &pre, int &rootIndex, vector<int> &mid, int l, int r) {
  if(rootIndex > pre.size() - 1 || l > r) {
    return NULL;
  }
  TreeNode* root = NULL;
  root = new TreeNode(pre[rootIndex]); 
  auto pos = find(mid.begin(), mid.end(), pre[rootIndex]) - mid.begin();
  rootIndex++;
  root->left = rebuild(pre, rootIndex, mid, l, pos - 1); 
  root->right = rebuild(pre, rootIndex,  mid, pos + 1, r); 
  return root;
}

void printTree(TreeNode* root) {
  if(root) {
    printTree(root->left);
    printTree(root->right);
    cout << root->val << endl;
  }
}

int main() {
  vector<int> pre{1,2,4,7,3,5,6,8};
  vector<int> mid{4,7,2,1,5,3,8,6};
  int rootIndex = 0;
  TreeNode* root = rebuild(pre, rootIndex, mid, 0, mid.size()-1);
  printTree(root);
}
