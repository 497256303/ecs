#include "binaryTreeNode.h"

binaryTreeNode* tree;
CString levelOrderOutput;
int thewideth[5];
int blank[10][10];
CString ele[10][10];
CString blankNumber[10][10];
CString theFinal[5];

int a[]={9,14,10,6,26,5,28,2,3,19,8,7,18,8,26,14,27,6,1,18,15};
int b[]={0,0,2,0,1,2,0,3,0,1,2,2,0,1,3,0,0,2,3,2,2};
int Size=sizeof(a)/sizeof(a[0]);

void createTree (int a[],int b[],binaryTreeNode* & tree,int size);
void exchange (binaryTreeNode* & tree);//��������������һ���ڵ����������
void exchangeLeftToRight (binaryTreeNode* & tree);//�����������Ķ������������ҽ���
void levelOrder (binaryTreeNode* tree);
//void widethOrder (binaryTreeNode* tree,int wide[],int j=1);
int treeWide(binaryTreeNode* tree);
void freeTree(binaryTreeNode* & tree);//�ͷ��� 