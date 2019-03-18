/* 题目：找到中序遍历中某个节点node的下个要访问的节点,假设每个节点都有指向父节点的指针
 * 解法：分情况讨论：
 *       1、若node有右子树，则返回右子树的最左边节点；
 *       2、若node无右子树，且它在parent的左边，则返回parent;
 *          若node无右子树，且它子parent的左边，则一直找到第一个以它所在的树为左子树的节点
 */
#include "base_data_struct.h"

using namespace std;

TreeNodeP<>* getLeftMost(TreeNodeP<>* node) {
  while(node->left) {
    node = node->left;
  }
  return node;
}

TreeNodeP<>* getInorderNext(TreeNodeP<>* node) {
  if(node == NULL)
    return NULL;

  if(node->right != NULL) {
    return getLeftMost(node->right);
  } else {
    TreeNodeP<>* parent = node->parent;
    while(parent != NULL && parent->left != node) {
      node = parent;
      parent = node->parent;
    }
    return parent;
  }
}
