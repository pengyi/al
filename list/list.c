#include "list.h"
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

void* listPop(struct list* l) {
  struct listNode* node = NULL;
  void* pval = NULL;
  if (NULL == l || NULL == l->tail) {
    return NULL;
  }
  if (l->tail == l->head) {
    node = l->tail;
    l->head = l->tail = NULL;
  } else {
    node = l->head;
    while(node->next != l->tail) {
      node = node->next;
    }
    l->tail = node;
    node = node->next;
    l->tail->next = NULL;
  }
  pval = node->val;
  free(node);
  l->len--;
  return pval;
}

int listIsEmpty(struct list* l) {
    if (NULL == l) {
        return 1;
    }
    if (NULL == l->head || NULL == l->tail || 0 == l->len) {
        return 1;
    }
    return 0;
}

int listInsert(struct list* l, int i, void* val) {
    int step = 0;
    struct listNode* pre, *cur;
    if (NULL == l || i < 0) {
        return -1;
    }
    if (i > l->len) {
        i = l->len;
    }
    struct listNode *node = (struct listNode*)malloc(sizeof(struct listNode));
    if (NULL == node) {
        return -1;
    }
    node->val  = val;
    node->next = NULL;
    if (listIsEmpty(l)) {
        l->head = l->tail = node;
        l->len  = 1;
    } else {
        pre = NULL;
        cur = l->head;
        while(step < i && cur != NULL) {
            pre = cur;
            cur = cur->next;
            step++;
        }
        if (NULL == pre) {
            node->next = l->head;
            l->head = node;
        } else if (NULL == cur) {
            l->tail->next = node;
            l->tail = node;
        } else {
            pre->next = node;
            node->next = cur;
        }
        l->len++;
    }
    return l->len;
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



