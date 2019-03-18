#include <stdio.h>
typedef struct tree_node {
  int val;
  struct tree_node *left, *right;
  tree_node(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
} TreeNode;
