/* 我最早写的c++代码，不够简洁，需要引入栈
 */
#include "data_struct.h"
#include <list>
using namespace std;

bool getPath(TreeNode* root, TreeNode* target, list<TreeNode*> &path) {
  if(!root)
    return false;
  if(root == target) {
    path.push_back(root);
    return true;
  }
  bool found = false;
  path.push_back(root);
  found = getPath(root->left, target, path);
  if(!found) {
    found = getPath(root->right, target, path);
  }
  if(!found)
    path.pop_back();
  return found;
}

TreeNode* getRes(list<TreeNode*> p1, list<TreeNode*> p2) {
  auto it1 = p1.begin();
  auto it2 = p2.begin();
  TreeNode* res = NULL;
  while(it1 != p1.end() && it2 != p2.end()) {
    if(*it1 == *it2)
      res = *it1;
    else
      break;
  }
  return res;
}

TreeNode* getLowest(TreeNode* root, TreeNode* p, TreeNode* q) {
  list<TreeNode*> path1, path2;
  getPath(root, p, path1);
  getPath(root, q, path2);
  return getRes(path1, path2);
}

