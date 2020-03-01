#ifndef _BTREE_H
#define _BTREE_H

#include <iostream>
#include <queue>//标准库里的队列

template<class T> class BinaryTree;


template<class T>
class TreeNode
{
public:
	TreeNode(){leftChild = NULL; rightChild = NULL;}
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
};


template<class T>
class BinaryTree
{
public:
	//二叉树可以进行的操作
	void Visit(TreeNode<T>* currentNode);
	void PreOrder();//前序遍历
	void PreOrder(TreeNode<T>* currentNode);
	void InOrder();//中序遍历
	void InOrder(TreeNode<T>* currentNode);
	void PostOrder();//后序遍历
	void PostOrder(TreeNode<T>* currentNode);
	void LevelOrder();//层序遍历
public:
	TreeNode<T> *root;
};



/******函数实现部分******/
/***********************/
/***********************/

template<class T>
void BinaryTree<T>::Visit(TreeNode<T>* currentNode)
{
	std::cout<< currentNode->data;
}

//前序遍历
template<class T>
void BinaryTree<T>::PreOrder()
{
	PreOrder(root);
}

template<class T>
void BinaryTree<T>::PreOrder(TreeNode<T>* currentNode)
{
	if(currentNode)
	{
		Visit(currentNode);
		PreOrder(currentNode->leftChild);
		PreOrder(currentNode->rightChild);
	}
}


//中序遍历
template<class T>
void BinaryTree<T>::InOrder()
{
	InOrder(root);
}

template<class T>
void BinaryTree<T>::InOrder(TreeNode<T> *currentNode)
{
	if(currentNode)
	{
		//递归
		InOrder(currentNode->leftChild);
		//显示当前节点 
		Visit(currentNode);
		InOrder(currentNode->rightChild);
	}
}

//后序遍历
template<class T>
void BinaryTree<T>::PostOrder()
{
	PostOrder(root);
}

template<class T>
void BinaryTree<T>::PostOrder(TreeNode<T>* currentNode)
{
	if(currentNode)
	{
		PostOrder(currentNode->leftChild);
		PostOrder(currentNode->rightChild);
		Visit(currentNode);
	}
}

//层序遍历
template<class T>
void BinaryTree<T>::LevelOrder()
{
	std::queue<TreeNode<T>*> q;
	TreeNode<T>* currentNode = root;
	while(currentNode)
	{
		Visit(currentNode);
		if(currentNode->leftChild)
			q.push(currentNode->leftChild);
		if(currentNode->rightChild)
			q.push(currentNode->rightChild);
		if(q.empty())
			return;
		currentNode = q.front(); 
		q.pop();
	}
}


#endif