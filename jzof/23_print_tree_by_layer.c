/* 纯C实现树的层序遍历
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct treenode {
  int val;
  struct treenode *left, *right;
} TreeNode;

typedef struct quenode {
  TreeNode* val;
  struct quenode* next;
} *QueNode;

typedef struct {
  int size;
  QueNode head; // head 为第一个元素
  QueNode tail; // tail 为最后一个元素
} Queue;

QueNode newNode(TreeNode* val) {
  QueNode tmp = (QueNode)(malloc(sizeof(struct quenode)));
  tmp->val = val;
  return tmp;
}

Queue* newQueue(){
  Queue *q = (Queue*)malloc(sizeof(Queue));
  q->head = q->tail = NULL;
  q->size = 0;
}

void enqueue(Queue* q, TreeNode* val) {
  q->size++;
  QueNode tmp = newNode(val);
  if(q->head == NULL) {
    q->head = q->tail = tmp;
  } else {
    q->tail->next = tmp;
    q->tail = tmp;
  }
}

void dequeue(Queue* q) {
  assert(q->size > 0);
  (q->size)--;
  QueNode tmp = q->head;
  q->head = tmp->next;
  free(tmp);
}

QueNode front(Queue* q){
  if(q->head != NULL) {
    return q->head;
  }
  return NULL;
}

TreeNode* buildTree(int l, int r) {
  if(l > r) return NULL;
  int mid = l + ((r-l) >> 1);
  TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
  root->val = mid;
  root->left = buildTree(l, mid-1);
  root->right = buildTree(mid+1, r);
  return root;
}

void printTreeInorder(TreeNode* root) {
  if(root) {
    printTreeInorder(root->left);
    printf("%d ", root->val);
    printTreeInorder(root->right);
  }
}

void printTreeByLevel(TreeNode* root) {
  Queue *q = newQueue();
  TreeNode *curLast  = root;
  TreeNode *nextLast = root;
  enqueue(q, root);
  while((q->size) > 0) {
    TreeNode* x = front(q)->val;
    dequeue(q);
    printf("%d ", x->val);
    if(x->left) {
      enqueue(q, x->left);
      nextLast = x->left;
    }
    if(x->right) {
      enqueue(q, x->right);
      nextLast = x->right;
    }
    if(x == curLast) {
      printf("\n");
      curLast = nextLast;
    }
  }
}

int main(){
  TreeNode* root = buildTree(1, 15);
  printf("by level: \n");
  printTreeByLevel(root);
  printf("\n");
  printf("inorder : ");
  printTreeInorder(root);
  printf("\n");
  return 0;
}
