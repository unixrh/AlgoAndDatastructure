/* 题目：打印出一棵树中所有和为sum的路径
 * 解法：把从根节点开始遍历的值都放到数组中，然后从后往前加，当和为sum时打印该段。使用树的层高作为数组的下标
 */

#include "base_data_struct.h"

int getDepth(TreeNode<>* root) {
  if(root == NULL)
    return 0;
  else
    return max(getDepth(root->left), getDepth(root->right)) + 1;
}

void print(vector<int> arr, int start, int end) {
  while(start <= end) {
    cout << arr[start++] << endl;
  }
}

void process(TreeNode<>* root, vector<int> path, int sum, int level) {
  if(root == NULL) {
    return;
  }

  path[level] = root->val;

  int t = 0;
  for(int i = level; i >= 0; i--) {
    t += path[i];
    if(t == sum) {
      print(path, i, level);
    }
  }

  process(root->left, path, sum, level+1);
  process(root->right, path, sum, level+1);
}

void printPaths(TreeNode<>* root, int sum) {
  int depth = getDepth(root);
  vector<int> path(depth);
  process(root, path, sum, 0);
}

