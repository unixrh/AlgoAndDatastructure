#include <stdio.h>
using namespace std;
typedef struct tree_node {
  int val;
  struct tree_node *left, *right;
  tree_node(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
} TreeNode;

typedef struct list_node {
  int val;
  struct list_node* next;
  list_node(int x) {
    val = x;
    next = NULL;
  }
} ListNode;
