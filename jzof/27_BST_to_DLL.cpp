/* 题目： 将一个二叉树，转为一个双向链表
 * 解法： 从最右边开始，将当前的节点的right指向头部，将头部的left指向当前
 *        将当前赋值给头部，然后去递归左边
 */
#include "../common/utils.h"

void convert(TreeNode* root, TreeNode** head) {
  if(root == NULL) return;
  convert(root->right, head);
  cout << root->val << endl;
  root->right = (*head);
  if(*head) {
    (*head)->left = root;
  }
  *head = root;
  convert(root->left, head);
}

int main(int argc, char* argv[]) {
  int num = atoi(argv[1]);
  TreeNode* root = CommonUtils::buildTree(1,num);
  TreeNode** head;
  *head = NULL;
  convert(root, head);
  TreeNode* res = *head;
  while(res) {
    cout << res->val << " ";
    TreeNode* tmp = res->right;
    res = tmp;
  }
  cout << endl;
  return 0;
}
