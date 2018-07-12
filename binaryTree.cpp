#include <stdlib.h>
#include <iostream>
  
/* 定义二叉树节点类型 */
typedef struct node {
    char data;
    struct node *lchild; 
	struct node *rchild;
}BiTNode, *BiTree;
 
/*先序创建*/
BiTree CreatBitTree() {
    char ch;
    BiTree b;
    /*此时输入的值有两种情况：一是输入#，二为
	要申请节点的存储值*/ 
    scanf("%c", &ch);
    /* 遇到空节点停止递归 ,这样某一节点
	的某一个孩子指向空*/
    if (ch == '#') {
        b = NULL;
    }
    /*不为空的话，那么这个孩子指向一个新的节点*/ 
    else {    
        b = (BiTree) malloc(sizeof(BiTNode));
        /* 建立根节点 */
        /*前面的输入即为初始化*/
        b->data = ch;
        /* 递归先序建立左子树 */
        b->lchild = CreatBitTree();
        /* 递归先序建立右子树 */
        b->rchild = CreatBitTree();
    }
    return b;
}
 
void PreOrder(BiTree t) { /* 二叉树的先序遍历算法 */
	if(t!=NULL) {
  		putchar  (t->data);
  		PreOrder(t->lchild);
  		PreOrder(t->rchild);
  	}
}
 
void InOrder(BiTree t) { /* 二叉树的先中序遍历算法 */
	if(t != NULL) {
  		InOrder(t->lchild);
  		putchar(t->data);
  		InOrder(t->rchild);
  	}
}
 
void PostOrder(BiTree t) { /* 二叉树的后序遍历算法 */
	if(t != NULL) {
  		PostOrder(t->lchild);
  		PostOrder(t->rchild);
  		putchar(t->data);
  	}
}
 
main() {
	BiTree T;
	T = CreatBitTree();
	PreOrder(T);
	printf("\n");
	InOrder(T);
	printf("\n");
	PostOrder(T);
} 