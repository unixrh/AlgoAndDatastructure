#include <iostream>
#include <queue>
#include <time.h>
#include "data_struct_def.h"

using namespace std;
class CommonUtils {
  public:
    static int* createIntArrOfSizeN(int n, int amp = 2) {
      int *a = new int[n];
      srand(time(NULL));
      for(int i = 0; i < n; i++) {
        a[i] = rand() % (amp * n);
      }
      return a;
    }

    static void printArr(int arr[], int len,  string prefix = ""){
      cout << prefix << " ";
      for(int i = 0; i < len; i++) {
        cout << arr[i] << " ";
      }
      cout << endl;
    }

    static void printList(ListNode* root) {
      while(root) {
        cout << root->val << "->";
        root = root->next;
      }
      cout << "NULL" << endl;
    }

    static TreeNode* buildTree(int l, int r) {
      if(l > r) return NULL;
      int mid = l + ((r-l) >> 1);
      TreeNode* root = new TreeNode(mid);
      root->left = buildTree(l, mid-1);
      root->right = buildTree(mid+1, r);
      return root;
    }

    static void printTreePreorder(TreeNode* root) {
      if(root){
        cout << root->val << " ";
        printTreePreorder(root->left);
        printTreePreorder(root->right);
      }
    }

    static void printTreeInorder(TreeNode* root) {
      if(root){
        printTreeInorder(root->left);
        cout << root->val << " ";
        printTreeInorder(root->right);
      }
    }

    static void printTreeByLayer(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()) {
        TreeNode* tmp = q.front();
        q.pop();
        if(!tmp) {
          cout << " N ";
          continue;
        }
        cout << " " << tmp->val << " ";
        q.push(tmp->left);
        q.push(tmp->right);
      }
      cout << endl;
    }
};
