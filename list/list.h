#ifndef __LIST_H
#define __LIST_H

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

struct list *listCreate();
int listLen(struct list* l);
void* listGetVal(struct list *l, int i);
int listPush(struct list *l, void *valPtr);
void* listPop(struct list* l);
void iterateList(struct list *l, void(*action)(struct listNode*));
int listInsert(struct list* l, int i, void* val);
void* listRemove(struct list* l, int i); 
int listIsEmpty(struct list* l);
int listDestroy(struct list* l);
#endif
