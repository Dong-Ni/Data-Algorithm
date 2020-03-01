#ifndef _BST_H
#define _BST_H

#include <iostream>

enum Boolean {FALSE, TRUE};

template<class T> class BST;


template<class T>
class Element//节点里的内容
{
public:
	T key;
	//添加更多的数据
};


template<class T>
class BstNode//树节点
{
	friend class BST<T>;
public:
	Element<T> getdata(){return data;}
private:
	Element<T> data;
	BstNode* leftChild;
	BstNode* rightChild;
	void display(int i);
};


template<class T>
class BST
{
public:
	BST(BstNode<T> *init = 0){root = init;}
	//~BST();
	Boolean Insert(const Element<T>& x);//插入,返回插入是否成功
	BstNode<T>* Search(const Element<T>& x);//查找x，找到了则返回指向这个节点的指针，没找到就返回空指针
	BstNode<T>* Search(BstNode<T>*, const Element<T>&);//递归版本的查找
	BstNode<T>* IterSearch(const Element<T>&);//迭代版本的查找
	//要增加Delete
	//要增加InOrder
	//      PreOrder
	//      PostOrder
	//      LevelOrder
	void display()
	{
		std::cout << "\n";
		if(root)
			root->display(1);//调用BstNode的display，从根节点开始显示出来
		else
			cout<< "这是一棵空树\n";
	}
private:
	BstNode<T>* root;
};


/******函数实现部分******/
/***********************/
/***********************/

template<class T>
void BstNode<T>::display(int i)//显示当前节点及左右子树所有节点的数据
{
	std::cout<< "position: " << i << "  data.key= " << data.key << std::endl;
	if(leftChild)
		leftChild->display(2*i);
	if(rightChild)
		rightChild->display(2*i + 1);
}

template<class T>
Boolean BST<T>::Insert(const Element<T> &x)
{
	BstNode<T> *p = root;
	BstNode<T> *q = 0;//q指向p的父节点
	//insert之前要先查找
	while(p)
	{
		q = p;
		if(x.key == p->data.key)
			return FALSE;//发生重复，失败，返回FALSE
		if(x.key < p->data.key)
			p = p->leftChild;
		else if(x.key > p->data.key)
				p = p->rightChild;
	}
	//找到的位置就是q
	p = new BstNode<T>;
	p->leftChild = p->rightChild =0;
	p->data = x;
	if(!root)
		root = p;
	else if(x.key < q->data.key)
		q->leftChild = p;
	else
		q->rightChild = p;
	return TRUE;
}


template<class T>
BstNode<T>* BST<T>::Search(const Element<T> &x)
{
	return Search(root, x);
}
   
template<class T>
BstNode<T>* BST<T>::Search(BstNode<T> *b, const Element<T> &x)//找到的是一个指针
{
	if(!b)
		return 0;
	if(x.key == b->data.key)
		return b;
	if(x.key < b->data.key)
		return Search(b->leftChild, x);
	else if(x.key > b->data.key)
		return Search(b->rightChild, x);
}
 

template<class T>
BstNode<T>* BST<T>::IterSearch(const Element<T> &x)
{
	for(BstNode<T> *t = root; t; )
	{
		if(x.key == t->data.key)
			return t;
		if(x.key < t->data.key)
			t = t->leftChild;
		else if(x.key > t->data.key)
			t = t->rightChild;
	}
	return 0;
}






#endif