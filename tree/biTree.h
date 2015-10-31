#ifndef __BI_TREE_H
#define __BI_TREE_H
#include <stdlib.h>

typedef struct binaryTree {
    void* val;
    struct binaryTree* l;
    struct binaryTree* r;
} *pBiTree, biTreeNode;



pBiTree createBiTree_r(void** in, int i, int len);
void destroyBiTree_r(pBiTree T);

void preTraverse_r(pBiTree T, void(*action)(pBiTree));
void inTraverse_r(pBiTree T, void(*action)(pBiTree));
void postTraverse_r(pBiTree T, void(*action)(pBiTree));


#endif

