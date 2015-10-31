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

void printInt(char* msg, int* p) {
    if (NULL == p) {
        printf("%s:invalid pointer\n", msg);
    } else {
      printf("%s: %d\n", msg, *p);
    }
}


int main(int argc, char* argv[]) {

  int a[] = {1, 2, 3, 4, 5};
  int b[] = {9, 8, 7, 6};

  int i, popVal;
  int* pVal;
  struct list *l = listCreate();
  if (NULL == l) {
    return -1;
  }
  printf("create list\n");
  for (i = 0; i < 5; ++i) {
    printf("insert num %d, The len %d\n", a[i], listPush(l, &a[i]));
  }
  popVal =*((int*)listPop(l));
  printf("pop val is %d\n", popVal);
  popVal =*((int*)listPop(l));
  printf("pop val is %d\n", popVal);
  printf("len %d\n", listInsert(l, 0, &b[0]));
  printf("len %d\n", listInsert(l, 4, &b[1]));
  printf("len %d\n", listInsert(l, 3, &b[2]));
  printf("len %d\n", listInsert(l, 10, &b[3]));
  pVal = (int*)listRemove(l, 1);
  printInt("pop val is", pVal);
  pVal = (int*)listRemove(l, 0);
  printInt("pop val is", pVal);
  pVal = (int*)listRemove(l, 5);
  printInt("pop val is", pVal);
  pVal = (int*)listRemove(l, 2);
  printInt("pop val is", pVal);
  iterateList(l, &printList);
  printf("\n");
  printf("The List len is:%d\n", listLen(l));
  
  pVal = (int*)listGetVal(l, 2);
  printInt("The 2th val is ", pVal);
  pVal = (int*)listGetVal(l, 5);
  printInt("The 5th val is ", pVal);
  pVal = (int*)listGetVal(l, 4);
  printInt("The 4th val is ", pVal);
  pVal = (int*)listGetVal(l, 1);
  printInt("The 1th val is ", pVal);

  listDestroy(l);
  printf("destroy list\n");
  return 0;
}
