/* 题目： 将一个二叉树，转为一个双向链表
 * 解法： 从最右边开始，将当前的节点的right指向头部，将头部的left指向当前
 *        将当前赋值给头部，然后去递归左边
 */
#include "base_data_struct.h"

void convert(TreeNode<>* root, TreeNode<>** head) {
  if(!root) return;
  convert(root->right, head);
  root->right = *head;
  if(*head) (*head)->left = root;
  *head = root;
  convert(root->left, head);
}
