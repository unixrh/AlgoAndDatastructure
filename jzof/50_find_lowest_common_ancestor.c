#include "data_struct.h"
TreeNode* getLowest(TreeNode* root, TreeNode* p, TreeNode* q) {
  if(!root || root == p || root == q) {
    return root;
  }
  TreeNode* leftSide = getLowest(root->left, p, q);
  TreeNode* rightSide = getLowest(root->right, p, q);
  if(leftSide && rightSide) return root;
  if(!leftSide) return rightSide;
  return leftSide;
}
