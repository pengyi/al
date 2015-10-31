#include "biTree.h"

pBiTree createBiTree_r(void** in, int i, int len) {
    void* val = NULL;
    pBiTree pNode;
    if (NULL == in || i < 0 || i >= len) {
        return NULL;
    }
    val = (void*)(*(in + i));
    if (NULL == val) {
        return NULL;
    }
    pNode = (pBiTree)malloc(sizeof(biTreeNode));
    pNode->val = val;
    pNode->l = createBiTree_r(in, 2 * i + 1, len);
    pNode->r = createBiTree_r(in, 2 * i + 2, len);
    return pNode;
}

 void destroyBiTree_r(pBiTree T) {
     pBiTree l,r;
     if (NULL == T) {
         return;
     }
     l = T->l;
     r = T->r;
     free(T);
     destroyBiTree_r(l);
     destroyBiTree_r(r);
 }

 void preTraverse_r(pBiTree T, void(*action)(pBiTree)) {
     if (NULL == T || NULL == action) {
         return;
     }
     action(T);
     preTraverse_r(T->l, action);
     preTraverse_r(T->r, action);
 }

void inTraverse_r(pBiTree T, void(*action)(pBiTree)) {
    if (NULL == T || NULL == action) {
        return;
    }
    inTraverse_r(T->l, action);
    action(T);
    inTraverse_r(T->r, action);
}


void postTraverse_r(pBiTree T, void(*action)(pBiTree)) {
    if (NULL == T || NULL == action) {
        return;
    }
    postTraverse_r(T->l, action);
    postTraverse_r(T->r, action);
    action(T);
}
