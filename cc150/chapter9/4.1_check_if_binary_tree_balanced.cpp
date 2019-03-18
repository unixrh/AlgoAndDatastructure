/* 判断一棵树是否平衡
 *
 */
#include "base_data_struct.h"
using namespace std;
class Solution {
public:
  /* 递归计算两个子树的高度
   */
    int getHeight(TreeNode<>* root) {
        if(root == NULL) {
            return 0;
        }
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    bool isBalanced1(TreeNode<>* root) {
        if(root == NULL) return true;
        int heightDiff = getHeight(root->left) - getHeight(root->right);
        if(abs(heightDiff) > 1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }

    /* 下面这个方法更好一些
     * 当有任何子树不平衡时，直接返回错误
     */
    int checkHeight(TreeNode<>* root) {
        if(root == NULL)
            return 0;
        int leftHeight = checkHeight(root->left);
        if(leftHeight == -1)
            return -1;
        int rightHeight = checkHeight(root->right);
        if(rightHeight == -1)
            return -1;

        int heightDiff = leftHeight - rightHeight;

        if(abs(heightDiff) > 1)
            return -1;
        else
            return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode<>* root) {
        if(checkHeight(root) == -1)
            return false;
        else
            return true;
    }
};
