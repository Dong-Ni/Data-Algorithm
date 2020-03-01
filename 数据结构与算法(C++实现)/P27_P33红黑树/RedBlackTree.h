#ifndef RED_BLACK_TREE_H_
#define RED_BLACK_TREE_H_

#include "Except.h"
#include "Wrapper.h"

template<class T>
class RedBlackTree;

template<class T>
class RedBlackNode;



template<class T>
class RedBlackTree
{
public:
	RedBlackTree(const T& nefInf);//构造函数
	~RedBlackTree();

	Cref<T> find(const T& x) const;
	Cref<T> findMin() const;
	Cref<T> findMax() const;
	bool isEmpty() const;
	void makeEmpty();

	enum {RED, BLACK};

	void insert(const T& x);//插入

	typedef RedBlackNode<T> Node;//用一个短一点的名字Node代替RedBlackNode<T>
//private:
public://为了测试，临时改成public
	Node *header;
	Node *nullNode;

	Node *current;
	Node *parent;//父节点
	Node *grand;//祖父节点
	Node *great;//曾祖父节点

	void reclaimMemory(Node* t) const;//从节点t开始，删除后面的所有结点，适合用递归

	void rotateWithLeftChild(Node* &k2) const;//带着左孩子向右转,k2是基准
	void rotateWithRightChild(Node* &k1) const;//带着右孩子向左转，k1是基准
	
	void doubleRotateWithLeftChild(Node* &k3) const;//双旋转，最终带着左孩子向右转
	void doubleRotateWithRightChild(Node* &k1) const;//双旋转，最终带着右孩子向左转

	void handleReorient(const T& item);//重新调整：1.两个孩子节点都是红色时 2.新插入的节点的父节点是红色时
	RedBlackNode<T>* rotate(const T& item, Node* theParent) const;//通用旋转函数


};


template<class T>
class RedBlackNode
{
//private:
public://为了测试，临时改成public
	friend class RedBlackTree<T>;
	T element;
	RedBlackNode *left;
	RedBlackNode *right;
	int color;

	RedBlackNode(const T& theElement = T(), RedBlackNode *lt = NULL, RedBlackNode *rt = NULL, int c = RedBlackTree<T>::BLACK)
		:element(theElement), left(lt), right(rt), color(c){}//构造函数
};


///////////函数实现部分///////////

/********************************************
name: RedBlackTree
description: 构造函数
********************************************/
template<class T>
RedBlackTree<T>::RedBlackTree(const T& nefInf)
{
	nullNode = new Node();
	nullNode->left = nullNode->right = nullNode;
	header = new Node(nefInf);
	header->left = header->right = nullNode;
}


/********************************************
name: ~RedBlackTree
description: 析构函数
********************************************/
template<class T>
RedBlackTree<T>::~RedBlackTree()
{
	makeEmpty();
	delete nullNode;
	delete header;
}


/********************************************
name: insert
description: 插入
********************************************/
template<class T>
void RedBlackTree<T>::insert(const T& x)
{
	current = parent = grand = header;
	nullNode->element = x;

	while(current->element != x)
	{
		great = grand;
		grand = parent;
		parent = current;
		//current = x < current->element ? current->left : current->right; //老师敲的
		//(current=x) < (current->element) ? (current=current->left) : (current=current->right);
		current = ( x<current->element ? current->left : current->right);
		
		//如果当前节点的左右两个孩子节点都是红色的，
		if(current->left->color == RED && current->right->color == RED)
			handleReorient(x);
	}

	if(current != nullNode)
		throw DuplicateItemException();

	current = new Node(x, nullNode, nullNode);

	if(x < parent->element)
		parent->left = current;
	else if(x > parent->element)
		parent->right = current;
	//自动平衡 -> 红黑树  
	////////重点////////
	handleReorient(x);
}


/********************************************
name: rotateWithLeftChild
description: 带着左孩子向右转
********************************************/
template<class T>
void RedBlackTree<T>::rotateWithLeftChild(Node* &k2) const
{
	Node *k1 = k2->left;
	k2->left = k1->right;//移动内侧孙子
	k1->right = k2;
	k2 = k1;//把k1旋转到顶上了,k1替代了k2的位置
}


/********************************************
name: rotateWithRightChild
description: 带着右孩子向左转
********************************************/
template<class T>
void RedBlackTree<T>::rotateWithRightChild(Node* &k1) const
{
	Node *k2 = k1->right;
	k1->right = k2->left;//移动内测孙子
	k2->left = k1;
	k1 = k2;//上升k2，成为根
}


/********************************************
name: doubleRotateWithRightChild
description: 双旋转，最终带着左孩子向右转
********************************************/
template<class T>
void RedBlackTree<T>::doubleRotateWithLeftChild(Node* &k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}


/********************************************
name: doubleRotateWithRightChild
description: 双旋转，最终带着右孩子向左转
********************************************/
template<class T>
void RedBlackTree<T>::doubleRotateWithRightChild(Node* &k1) const
{
	rotateWithLeftChild(k1->right);
	rotateWithRightChild(k1);
}


/********************************************
name: handleReorient
description: 
  重新调整：1.两个孩子节点都是红色时 2.新插入的节点的父节点是红色时
********************************************/
template<class T>
void RedBlackTree<T>::handleReorient(const T& item)
{
	//变色
	//1.如果当前节点的左右两个孩子节点都是红色的,先调整颜色
	current->color = RED;
	current->left->color = BLACK;
	current->right->color = BLACK;
	
	//2.新插入的节点的父节点是红色时
	if(parent->color == RED)
	{
		grand->color = RED;
		if(item < grand->element  !=  item < parent->element)//判断是否为内部孙子
			parent = rotate(item, grand);//是就多加一次旋转
		current = rotate(item, great);
		current->color = BLACK;
	}
	header->right->color = BLACK;
}


/********************************************
name: rotate
description: 通用旋转函数
********************************************/
template<class T>
RedBlackNode<T>* RedBlackTree<T>::rotate(const T& item, Node* theParent) const
{
	if(item < theParent->element)
	{
		item < theParent->left->element  ?  rotateWithLeftChild(theParent->left)  :  rotateWithRightChild(theParent->left);
		return theParent->left;
	}
	else if(item > theParent->element)
	{
		item < theParent->right->element  ?  rotateWithLeftChild(theParent->right)  : rotateWithRightChild(theParent->right);
		return theParent->right;
 	}
}


/********************************************
name: isEmpty
description: 判断红黑树是否为空
********************************************/
template<class T>
bool RedBlackTree<T>::isEmpty() const
{
	return header->right == nullNode;
}


/********************************************
name: makeEmpty
description: 清空，删除所有节点
********************************************/
template<class T>
void RedBlackTree<T>::makeEmpty()
{
	reclaimMemory(header->right);//从跟节点开始清除
	header->right = nullNode;
}


/********************************************
name: reclaimMemory
description: 从节点t开始，删除后面的所有结点
********************************************/
template<class T>
void RedBlackTree<T>::reclaimMemory(Node* t) const
{
	if(t != t->left)
	{
		reclaimMemory(t->left);
		reclaimMemory(t->right);
		delete t;
	}
}


/********************************************
name: findMin
description: 找最小，返回引用
********************************************/
template<class T>
Cref<T> RedBlackTree<T>::findMin() const
{
	if(isEmpty())
		return Cref<T>(); 

	Node* itr = header->right;
	while(itr->left != nullNode)
		itr = itr->left;
	return Cref<T>(itr->element);
}


/********************************************
name: findMax
description: 找最大,返回引用
********************************************/
template<class T>
Cref<T> RedBlackTree<T>::findMax() const
{
	if(isEmpty())
		return Cref<T>(); 

	Node* itr = header->right;
	while(itr->right != nullNode)
		itr = itr->right;
	return Cref<T>(itr->element);
}


/********************************************
name: find
description: 查找x，返回引用
********************************************/
template<class T>
Cref<T> RedBlackTree<T>::find(const T& x) const
{
	nullNode->element = x;
	
	Node* curr = header->right;

	for(;;)
	{
		if(x < curr->element)
			curr = curr->left;
		else if(x > curr->element)
			curr = curr->right;
		    
			else if(curr != nullNode)//找到了
				return Cref<T>(curr->element);
				else//没找到
					return Cref<T>();
	}
}


/********************************************
name: 
description: 遍历等,
********************************************/

#endif