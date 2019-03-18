#include "base_data_struct.h"
#include <vector>

using namespace std;

// 这种做法频繁申请内存，时间空间的消耗都比较大
TreeNode<>* sortedArrayToBST(vector<int>& nums) {
  if(nums.size() <= 0)
    return NULL;
  int len = nums.size();
  int mid = len / 2;
  TreeNode<>* node = new TreeNode<>(nums[mid]);
  vector<int> left(nums.begin(), nums.begin() + mid);
  vector<int> right(nums.begin()+mid+1, nums.end());
  node->left = sortedArrayToBST(left);
  node->right = sortedArrayToBST(right);
  return node;
}

// 这样的做法实际上使得以上方法的弊端得到规避
TreeNode<>* build(vector<int> arr, int l, int r) {
  if(l > r)
    return NULL;
  int mid = (l + r) / 2;
  TreeNode<> *node = new TreeNode<>(arr[(l+r)/2]);

  node->left = build(arr, l, mid-1);
  node->right = build(arr, mid+1, r);
  return node;
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << argv[0] << " num" << endl;
    exit(1);
  }
  vector<int> x;
  for(int i = 0;i < atoi(argv[1]); i++) {
    x.push_back(i);
  }
  sortedArrayToBST(x);
  return 0;
}
