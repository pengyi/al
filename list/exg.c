#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void printList(struct listNode* n) {
  int* valPtr;
  if (NULL == n) {
    return;
  }
  valPtr = (int*)(n->val);
  printf("%d ", *valPtr);
}

int main(int argc, char* argv[]) {

  int a[] = {1, 2, 3, 4, 5};
  int b[] = {9, 8, 7, 6};

  int i, popVal;
  struct list *l = listCreate();
  if (NULL == l) {
    return -1;
  }
  for (i = 0; i < 5; ++i) {
    printf("len %d\n", listPush(l, &a[i]));
  }
  popVal =*((int*)listPop(l));
  printf("pop val is %d\n", popVal);
  popVal =*((int*)listPop(l));
  printf("pop val is %d\n", popVal);
  printf("len %d\n", listInsert(l, 0, &b[0]));
  printf("len %d\n", listInsert(l, 4, &b[1]));
  printf("len %d\n", listInsert(l, 3, &b[2]));
  iterateList(l, &printList);
  printf("\n");
  return 0;
}
