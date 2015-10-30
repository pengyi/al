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
  iterateList(l, &printList);
  printf("\n");
  return 0;
}
