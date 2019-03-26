/* 判断一棵树t2是否为t1的子树
 * 注意有相同值节点的情况，应该继续遍历，直到t1为空
 */

#include "../common/utils.h"

bool check(TreeNode* t1, TreeNode* t2) {
  if(!t1 && !t2) return true;
  if(!t1 || !t2) return false;
  if(t1->val != t2->val) return false;
  return check(t1->left, t2->left) && check(t1->right, t2->right);

}

bool isSubTree(TreeNode* t1, TreeNode* t2) {
  if(!t1) return false;
  if(check(t1,t2)) return true;
  return isSubTree(t1->left, t2) || isSubTree(t1->right, t2);
}

