
#include<stdio.h>
#include "biTree.h"


void** getPointers(int* a, int len) {
    int i;
    void **p;
    p = (void**)malloc(sizeof(void*) * len);
    for(i = 0;i < len; ++i) {
        if (0 == a[i]) {
            *(p + i) = NULL;
        } else {
            *(p + i) = (void*)&a[i];
        }
    }
    return p;
}

void printNode(pBiTree T) {
    int* pval;
    if (NULL == T) {
        return;
    }
    pval =(int*)T->val;
    printf("%d ", *pval);
}

void printArray(int* a, int len) {
    int i;
    for(i = 0; i < len; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {

    int a[] = {1, 2, 3, 4, 0, 0, 7};
    int len = sizeof(a)/sizeof(a[0]);
    printf("The input array is:\n");
    printArray(a, len);
    printf("array len is %d\n", len);
    void** pa = getPointers(a, len);
    pBiTree T;
    T = createBiTree_r(pa, 0, len);
    printf("preorder traverse sequence is:\n");
    preTraverse_r(T, printNode);
    printf("\n");
    printf("inorder traverse sequence is:\n");
    inTraverse_r(T, printNode);
    printf("\n");
    printf("postorder traverse sequence is:\n");
    postTraverse_r(T, printNode);
    printf("\n");
    return 0;
}
