/* 有两个很大的树T1、T2，判断T2是否为T1的子串
 * 解法1：遍历树得到字符串，其中NULL用0或其他特殊标识，若T2的前中序遍历分别对应T1前中序遍历的子串，则可以判断true；这个方法的问题在于构建这样的副本成本太高;时间内存复杂度均为O(m+n);
 * 解法2：在T1中找到和T2root等值的节点，然后递归第去比较每个节点是否相同。空间复杂度为O(log(m) + log(n))，时间复杂度为O(m+k*n)，其中k表示T1中与T2root相同点的个数
 */
#include "base_data_struct.h"

bool isTreeMatch(TreeNode<>* t1, TreeNode<>* t2) {
  if(t1 == NULL && t2 == NULL)
    return true;
  if(t1 == NULL || t2 == NULL)
    return false;

  if(t1->val != t2->val)
    return false;
  return isTreeMatch(t1->left, t2->left) && isTreeMatch(t1->right, t2->right);
}

bool isSub(TreeNode<>* t1, TreeNode<>* t2) {
  if(t1 == NULL)
    return false;
  if(t1->val == t2->val) {
    return isTreeMatch(t1, t2);
  }
  return isSub(t1->left, t2) || isSub(t1->right, t2);
}

bool isContain(TreeNode<>* t1, TreeNode<>* t2) {
  if(t2 == NULL)
    return true;
  return isSub(t1, t2);
}
