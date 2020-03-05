//自己实现二叉查找树 2020.03.06
#ifndef BST_H
#define BST_H

template <class T>
class Element  //数据封装成类 方便扩展
{
public:
	T  data;
};

template <class T>
class BSTNode
{
public:
	Element<T>   data;
	BSTNode<T>*  m_pLeftNode;
	BSTNode<T>*  m_pRightNode;
};

template <class T>
class BST
{

public:
	//展示
	template <class T>
	void DisPlay(BSTNode<T>* node);

	//插入
	template <class T>
	void Insert(Element<T>* ele);

	//递归查找
	template <class T>
	void Search(Element<T>* ele);
	template <class T>
	void Search(BSTNode<T>* ele, Element<T>* ele);

	//循环查找
	template <class T>
	void SearchOrd(Element<T>* ele);

	//删除
	template <class T>
	void Delete(Element<T>* ele);


public:
	BSTNode<T>* root;

};

#endif
