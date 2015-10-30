#include <stdlib.h>
struct listNode {
  void* val;
  struct listNode *next;
};

struct list {
  struct listNode *head;
  struct listNode *tail;
  int len;
};

struct list *listCreate() {
  struct list *newList = (struct list*)malloc(sizeof(struct list));
  if (NULL == newList) {
    return NULL;
  }
  newList->head = NULL;
  newList->tail = NULL;
  newList->len  = 0;
  return newList;
}

int listPush(struct list *l, void *valPtr) {
  if (NULL == l || NULL == valPtr) {
    return -1;
  }
  struct listNode *node = (struct listNode*)malloc(sizeof(struct listNode));
  if (NULL == node) {
    return -1;
  }
  node->val  = valPtr;
  node->next = NULL;
  if (NULL == l->head && NULL == l->tail) {
    l->head = l->tail = node;
  } else {
    l->tail->next = node;
    l->tail = node;
  }
 return  ++l->len;
}

void iterateList(struct list *l, void(*action)(struct listNode*)) {
  if (NULL == l || NULL == action) {
    return;
  }
  struct listNode* p = l->head;

  while(NULL != p) {
    action(p);
    p = p->next;
  }
}












