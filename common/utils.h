#include <iostream>
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
};

