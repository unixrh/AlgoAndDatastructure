/* 纯C实现树的层序遍历
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct treenode {
  int val;
  struct treenode *left, *right;
} TreeNode;

typedef struct listnode {
  TreeNode* val;
  struct listnode* next;
} ListNode, *QueNode;

typedef struct {
  int size;
  QueNode head; // head->next为第一个元素
  QueNode tail; // tail 为最后一个元素
} Queue;

Queue* createQueue(){
  Queue *q = (Queue*)malloc(sizeof(Queue));
  q->head = (ListNode*)(malloc(sizeof(ListNode)));
  q->tail = q->head;
  q->size = 0;
}

void enqueue(Queue* q, TreeNode* val) {
  q->size++;
  ListNode* tmp = (ListNode*)(malloc(sizeof(ListNode)));
  tmp->val = val;
  q->tail->next = tmp;
  q->tail = tmp;
}

void dequeue(Queue* q) {
  assert(q->head != NULL);
  (q->size)--;
  ListNode* tmp = q->head->next;
  if(tmp) {
    q->head->next = tmp->next;
    free(tmp);
  }
}

ListNode* front(Queue* q){
  if(q->head != NULL) {
    return q->head->next;
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
  Queue *q = createQueue();
  enqueue(q, root);
  while((q->size) > 0) {
    ListNode* tmp = front(q);
    TreeNode* x = tmp->val;
    printf("%d ", x->val);
    if(x->left)
      enqueue(q, x->left);
    if(x->right)
      enqueue(q, x->right);
    dequeue(q); // dequeue必须放在最后，否则dequeue将内存释放了就么得打印了
  }
}

int main(){
  TreeNode* root = buildTree(1, 16);
  printf("inorder : ");
  printTreeInorder(root);
  printf("\n");
  printf("by level: ");
  printTreeByLevel(root);
  printf("\n");
  return 0;
}
