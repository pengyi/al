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

int listLen(struct list* l) {
    if (NULL == l) {
        return 0;
    }
    return l->len;
}

void* listGetVal(struct list *l, int i) {
    struct listNode* p;
    int step = 1;
    if (NULL == l || i <= 0 || i > l->len) {
        return NULL;
    }
    p = l->head;
    while (step < i && p != NULL) {
        p = p->next;
        step++;
    }
    if (NULL == p) {
        return NULL;
    }
    return p->val;
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

void* listRemove(struct list* l, int i) {
    struct listNode* pre, *node;
    void* val;
    int step = 1;
    if (NULL == l || i <= 0 || i > l->len) {
        return NULL;
    }
    if (listIsEmpty(l)) {
        return NULL;
    }
    pre  = NULL;
    node = l->head;
    while(step < i && node != NULL) {
        pre  = node;
        node = node->next;
        step++;
    }

    if (1 == i) {
        l->head = node->next;
    } else if (i == l->len) {
        l->tail   = pre;
        pre->next = NULL;
    } else {
        pre->next = node->next;
    }
    l->len--;
    val = node->val;
    free(node);
    return val;
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

int listDestroy(struct list* l) {
    struct listNode* node, *p;
    if (NULL == l) {
        return 1;
    }
    p = l->head;
    while(p != NULL) {
        node = p;
        p = p->next;
        free(node);
    }
    free(l);
    return 1;
}


