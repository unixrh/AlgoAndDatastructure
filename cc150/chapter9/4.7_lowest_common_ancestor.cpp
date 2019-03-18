/* 题目：找到二叉树中，两个节点的最低公共祖先
 * 解法：递归整个树，若找到q则返回q，遇到p则返回p，若遇到NULL则返回NULL;
 *       最终递归回退到能返回的那个节点，若在这个点能找到p和q，则它就是结果；
 *       若只能找打p，说明q为p的一个子节点(假设pq都在树种)，此时p为结果。
 *
 *
 *       ********** 另一个更直观的思路 ********
 *       找到第一个使得pq不在同一边的点
 */
#include "base_data_struct.h"

bool covers(TreeNode<>* root, TreeNode<>* p) {
  if(root == NULL) return false;
  if(root == p) return true;
  return covers(root->left, p) || covers(root->right, p);
}

TreeNode<>* divNode(TreeNode<>* root, TreeNode<>* p, TreeNode<>* q) {
  if(root == NULL) return NULL;
  if(root == p || root == q) return root;

  bool is_p_on_left = covers(root->left, p);
  bool is_q_on_left = covers(root->left, q);

  // 在root这个节点上开始，p和q开始不在一边了
  if(is_p_on_left != is_q_on_left) {
    return root;
  }

  // 如果他们在同一边，则继续递归这一边的子树
  TreeNode<>* child = is_p_on_left ? root->left : root->right;
  return divNode(child, p, q);
}

using namespace std;

TreeNode<>* search(TreeNode<>* root, TreeNode<>* p, TreeNode<>* q) {
  if(root == NULL || root == p || root == q) {
    return root;
  }

  TreeNode<>* leftSide = search(root->left, p, q);
  TreeNode<>* rightSide = search(root->right, p, q);

  if(leftSide && rightSide) return root;
  if(!leftSide) return rightSide;
  return leftSide;
}
