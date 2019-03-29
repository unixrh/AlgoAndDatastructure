/* 不考虑首尾节点，任何路径都算的话
 */

#include "../common/utils.h"

class Solution{
  public:
    int pathSum(TreeNode* root, int sum) {
      if(root == NULL) return 0;
      return helper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int helper(TreeNode* root, int pre, int &sum) {
      if(root == NULL) return 0;
      int current = pre + root->val;
      return (current == sum) 
        + helper(root->left, current, sum)
        + helper(root->right, current, sum);
    }
};

