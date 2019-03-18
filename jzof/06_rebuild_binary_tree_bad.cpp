#include <iostream>
#include <vector>
#include "data_struct.h"

using namespace std;
TreeNode* rebuild(vector<int> pre, int &rootIndex, vector<int> mid) {
  if(rootIndex > (int)pre.size()-1 || pre.size() == 0 || mid.size() == 0) {
    return NULL;
  }
  TreeNode* root = NULL;
  root = new TreeNode(pre[rootIndex]); 
  auto pos = find(mid.begin(), mid.end(), pre[rootIndex]) - mid.begin();

  rootIndex++;
  root->left = rebuild(pre, rootIndex, vector<int>(mid.begin(), mid.begin()+pos)); 
  root->right = rebuild(pre, rootIndex,  vector<int>(mid.begin()+pos+1, mid.end())); 
  return root;
}

void printTree(TreeNode* root) {
  if(root) {
    printTree(root->left);
    printTree(root->right);
    cout << root->val << endl;
  }
}

int main() {
  vector<int> pre{1,2,4,7,3,5,6,8};
  vector<int> mid{4,7,2,1,5,3,8,6};
  int rootIndex = 0;
  TreeNode* root = rebuild(pre, rootIndex, mid);
  printTree(root);
}
