#ifndef MAXHEAP_H 
#define MAXHEAP_H

#include <iostream>

template <class T>
class MaxHeap
{
public:
	MaxHeap(int nSize = 10);
	~MaxHeap();

	bool IsEmpty();

	void Push(const T& t);
	void TrickUp(int nIndex);  //向上渗透
	void Pop();
	void TrickDown(int nIndex); //向下渗透
	T Top();

private:
	int m_nMaxSize;
	int m_nCurrentSize;
	T* m_pArray;
};

template <class T>
MaxHeap<T>::MaxHeap(int nSize) 
	: m_nMaxSize(nSize), 
	m_nCurrentSize(0),
	m_pArray(NULL)
{
	if (nSize < 1)
	{
		std::cout << "MaxHeap size must big than 1." << std::endl;
	}
	m_pArray = new T[nSize];
}

template<class T>
MaxHeap<T>::~MaxHeap()
{
	delete[]m_pArray;
}

template<class T>
bool MaxHeap<T>::IsEmpty()
{
	return m_nCurrentSize == 0;
}

template<class T>
void MaxHeap<T>::Push(const T& t)
{
	if (m_nCurrentSize == m_nMaxSize)
	{
		std::cout << "The MaxHeap is Full." << std::endl;
	}
	m_pArray[m_nCurrentSize] = t;
	TrickUp(m_nCurrentSize++);
}

template<class T>
void MaxHeap<T>::TrickUp(int nIndex)
{
	T nBottom = m_pArray[nIndex];
	int nParent = (nIndex - 1) / 2;
	while (nIndex > 0 && nBottom > m_pArray[nParent])
	{
		m_pArray[nIndex] = m_pArray[nParent];
		nIndex = nParent;
		nParent = (nParent - 1) / 2;
	}

	m_pArray[nIndex] = nBottom;
}

template<class T>
void MaxHeap<T>::Pop()
{
	if (IsEmpty())
	{
		std::cout << "MaxHeap is Empty." << std::endl;
		return;
	}
	m_pArray[0] = m_pArray[--m_nCurrentSize];
	TrickDown(0);
}

template<class T>
void MaxHeap<T>::TrickDown(int nIndex)
{
	T HeadNode = m_pArray[nIndex];
	while (nIndex < m_nCurrentSize / 2)
	{
		int nLeft = nIndex * 2 + 1;
		int nRight = nLeft + 1;
		int nMaxIndex;
		if (nRight < m_nCurrentSize && m_pArray[nRight] > m_pArray[nLeft])
		{
			nMaxIndex = nRight;
		}
		else
		{
			nMaxIndex = nLeft;
		}

		if (HeadNode >= m_pArray[nMaxIndex]) break;
		m_pArray[nIndex] = m_pArray[nMaxIndex];
		nIndex = nMaxIndex;
	}

	m_pArray[nIndex] = HeadNode;
}

template<class T>
T MaxHeap<T>::Top()
{
	if (m_nCurrentSize == 0)
	{
		std::cout << "The MaxHeap is Empty." << std::endl;
		return NULL;
	}

	return m_pArray[0];
}

#endif
