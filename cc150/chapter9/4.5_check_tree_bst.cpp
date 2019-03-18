/* 题目：判断一棵树是否为二叉查找树
 * 解法：判断每个节点是否在应在的范围内。
 */
#include <iostream>
#include "base_data_struct.h"
bool check(TreeNode<>* root, long min, long max) {
  if(root == NULL)
    return true;

  if(min >= root->val || max <= root->val) {
    return false;
  }

  return (check(root->left, min, root->val) && check(root->right, root->val, max));
}

bool isValidBST(TreeNode<>* root) {
  return check(root, LONG_MIN, LONG_MAX);
}

