//�Լ�ʵ�ֶ�������� 2020.03.06
#ifndef BST_H
#define BST_H

template <class T>
class Element  //���ݷ�װ���� ������չ
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
	//չʾ
	template <class T>
	void DisPlay(BSTNode<T>* node);

	//����
	template <class T>
	void Insert(Element<T>* ele);

	//�ݹ����
	template <class T>
	void Search(Element<T>* ele);
	template <class T>
	void Search(BSTNode<T>* ele, Element<T>* ele);

	//ѭ������
	template <class T>
	void SearchOrd(Element<T>* ele);

	//ɾ��
	template <class T>
	void Delete(Element<T>* ele);


public:
	BSTNode<T>* root;

};

#endif
