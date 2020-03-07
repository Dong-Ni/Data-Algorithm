//自己实现二叉查找树 2020.03.06
#ifndef BST_H
#define BST_H

template <class T>
class Element  //数据封装成类 方便扩展
{
public:
	T  key;
};

template <class T>
class BSTNode
{
public:
	void DisPlay(int i)
	{
		std::cout << "position: " << i << " data.key= " << data.key << std::endl;
		if (m_pLeftNode)
			m_pLeftNode->DisPlay(2 * i);
		if (m_pRightNode)
			m_pRightNode->DisPlay(2 * i + 1);
	}

	Element<T>   data;
	BSTNode<T>*  m_pLeftNode;
	BSTNode<T>*  m_pRightNode;
};

template <class T>
class BST
{
public:
	BST(BSTNode<T>* node = NULL) : root(node){}

	//展示
	void DisPlay()
	{
		if (root) root->DisPlay(1);
		else std::cout << "Tree is Empty." << std::endl;
	}

	//插入
	template <class T>
	bool Insert(Element<T>& ele)
	{
		BSTNode<T>* p = root;
		BSTNode<T>* q = NULL;
		while (p)
		{
			q = p;
			if (p->data.key == ele.key) return false;
			else if (p->data.key > ele.key) p = p->m_pLeftNode;
			else p = p->m_pRightNode;
		}

		BSTNode<T>* pNew = new BSTNode<T>;
		pNew->data = ele;
		pNew->m_pLeftNode = NULL;
		pNew->m_pRightNode = NULL;

		if (!root) root = pNew;
		else if (pNew->data.key < q->data.key) q->m_pLeftNode = pNew;
		else q->m_pRightNode = pNew;
		return true;
	}

	//递归查找
	template <class T>
	BSTNode<T>* Search(Element<T>& ele)
	{
		return Search(root, ele);
	}
	template <class T>
	BSTNode<T>* Search(BSTNode<T>* node, Element<T>& ele)
	{
		if (!node) return NULL;
		if (node->data.key == ele.key) return node;
		else if (node->data.key > ele.key)  return Search(node->m_pLeftNode, ele);
		else return Search(node->m_pRightNode, ele);
	}

	//循环查找
	template <class T>
	BSTNode<T>* SearchOrd(Element<T>& ele)
	{
		BSTNode<T>* t = root;
		while (t)
		{
			if (t->data.key == ele.key) return t;
			else if (t->data.key > ele.key) t = t->m_pLeftNode;
			else t = t->m_pRightNode;
		}

		return NULL;
	}

	//删除
	template <class T>
	void Delete(Element<T>* ele)
	{
		BSTNode<T>* node = Search(ele);
		if (!node) return false;
		else
		{
			if (node->m_pLeftNode) delete node->m_pLeftNode;
			if (node->m_pRightNode) delete node->m_pRightNode;
			delete node;
		}
	}

public:
	BSTNode<T>* root;
};

#endif
