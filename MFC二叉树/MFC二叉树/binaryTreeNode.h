#include <string>
using namespace std;

#pragma once
struct binaryTreeNode
{
	int element;
	int Zpos;
	int Hpos;
	binaryTreeNode * leftChild,* rightChild,*parent;

	binaryTreeNode()
	{
		leftChild=rightChild=NULL;
	}

	binaryTreeNode(const int & theElement)
	{
		element=theElement;
		leftChild=rightChild=NULL;
	}

	binaryTreeNode(const int & theElement,binaryTreeNode* theLeftChild,binaryTreeNode* theRightChild)
	{
		element=theElement;
		leftChild=theLeftChild;
		rightChild=theRightChild;
	}
};