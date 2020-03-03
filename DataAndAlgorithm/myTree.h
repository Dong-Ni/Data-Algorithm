//�Լ�ʵ�ֶ����� 2020.03.04
#ifndef MYTREE_H
#define MYTREE_H
#include <iostream>
#include <queue>

template<class T>
class TreeNode
{
public:
	TreeNode() 
	{
		m_pRight = NULL; 
		m_pLeft = NULL;
	};

public:  //д��public �������
	T data;
	TreeNode<T>* m_pRight;
	TreeNode<T>* m_pLeft;
};

template<class T>
class MyTree
{
public:
	MyTree() { root = NULL; };

	void Visit(TreeNode<T>* currentNode);

	//�������  ������
	void InOrder();
	void InOrder(TreeNode<T>* currentNode);

	//ǰ�����  ������
	void PreOrder();
	void PreOrder(TreeNode<T>* currentNode);

	//�������  ������
	void PostOrder();
	void PostOrder(TreeNode<T>* currentNode);

	//������� �������
	void LevelOrder();
	void LevelOrder(TreeNode<T>* currentNode);

public: //ͬ��
	TreeNode<T>* root;
};

template<class T>
void MyTree<T>::Visit(TreeNode<T>* currentNode)
{
	if (currentNode == NULL) return;
	std::cout << currentNode->data;
}

template<class T>
void MyTree<T>::InOrder()
{
	InOrder(root);
}

template<class T> // a/b*c-d+e
void MyTree<T>::InOrder(TreeNode<T>* currentNode)
{
	if (currentNode == NULL) return;
	InOrder(currentNode->m_pLeft);
	Visit(currentNode);
	InOrder(currentNode->m_pRight);
}

template<class T> 
void MyTree<T>::PreOrder()
{
	PreOrder(root);
}

template<class T> // /*-+abcde
void MyTree<T>::PreOrder(TreeNode<T>* currentNode)
{
	if (currentNode == NULL) return;
	Visit(currentNode);
	PreOrder(currentNode->m_pLeft);
	PreOrder(currentNode->m_pRight);
}

template<class T>
void MyTree<T>::PostOrder()
{
	PostOrder(root);
}

template<class T> //  ab/c*d-e+
void MyTree<T>::PostOrder(TreeNode<T>* currentNode)
{
	if (currentNode == NULL) return;
	PostOrder(currentNode->m_pLeft);
	PostOrder(currentNode->m_pRight);
	Visit(currentNode);
}

template<class T> 
void MyTree<T>::LevelOrder()
{
	LevelOrder(root);
}
template<class T> //  +-e*d/cab
void MyTree<T>::LevelOrder(TreeNode<T>* currentNode)
{
	std::queue<TreeNode<T>*> queueTmp;
	while (currentNode)
	{
		Visit(currentNode);
		if (currentNode->m_pLeft) queueTmp.push(currentNode->m_pLeft);
		if (currentNode->m_pRight) queueTmp.push(currentNode->m_pRight);
		if (!queueTmp.empty())
		{
			currentNode = queueTmp.front();
			queueTmp.pop();
		}
		else
		{
			currentNode = NULL;
		}
	}
}

#endif
