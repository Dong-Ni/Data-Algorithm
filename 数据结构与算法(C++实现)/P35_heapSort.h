#ifndef _HEAP_SORT_
#define _HEAP_SORT_


template<class T>
class MaxHeap
{
public:
	MaxHeap(int mx = 10);
	virtual ~MaxHeap();

	bool IsEmpty();
	void Push(const T&);
	void Pop();
	const T& Top() const;
private:
	T* heapArray;
	int maxSize;
	int currentSize;

	void trickleUp(int index);//向上渗透
	void trickleDown(int index);//向下渗透
};


////////函数实现部分////////

/**************************
name: MaxHeap
description： 构造函数
**************************/
template<class T>
MaxHeap<T>::MaxHeap(int mx = 10)
{
	if(mx<1)
		throw "max size must be >= 1.";
	maxSize = mx;
	currentSize = 0;
	heapArray = new T[maxSize];
}


/**************************
name: ~MaxHeap
description： 析构函数
**************************/
template<class T>
MaxHeap<T>::~MaxHeap()
{
	delete[] heapArray;
}


/**************************
name: IsEmpty
description：判断堆是否为空 
**************************/
template<class T>
bool MaxHeap<T>::IsEmpty()
{
	return currentSize == 0;
}


/**************************
name: Push
description：插入 
**************************/
template<class T>
void MaxHeap<T>::Push(const T& e)
{
	if(currentSize == maxSize)
		throw "MaxHeap is full.";
	heapArray[currentSize] = e;//当前已有的最后一个节点的下一个位置
	//向上渗透/向上冒泡
	trickleUp(currentSize++);
}


/**************************
name: Pop
description：删除堆顶（根节点） 
**************************/
template<class T>
void MaxHeap<T>::Pop()
{
	heapArray[0] = heapArray[--currentSize];//currentSize是空位，最后一个数据在currentSize的前一个
	trickleDown(0);
}


/**************************
name: Top
description：查看堆顶
**************************/
template<class T>
const T& MaxHeap<T>::Top() const
{
	return heapArray[0];
}


/**************************
name: trickleUp
description： 向上渗透/冒泡
**************************/
template<class T>
void MaxHeap<T>::trickleUp(int index)
{
	int parent = (index-1) / 2;
	T bottom = heapArray[index];//为做交换，设置一个临时数据
	while(index>0  && heapArray[parent]<bottom)
	{
		heapArray[index] = heapArray[parent];
		index = parent;
		parent = (parent-1) / 2;
	}
	heapArray[index] = bottom;
}


/**************************
name: trickleDown
description： 向下渗透
**************************/
template<class T>
void MaxHeap<T>::trickleDown(int index)
{
	int largerChild;
	T top = heapArray[index];//临时位置，用于存放heapArray[index]
	while(index < currentSize/2)//到最后一层的上一层即可
	{
		int leftChild = 2*index + 1;
		int rightChild = leftChild + 1;
		if(rightChild<currentSize && heapArray[leftChild]<heapArray[rightChild]) 
			largerChild = rightChild;
		else
			largerChild = leftChild;

		if(top >= heapArray[largerChild])
			break;
		heapArray[index] = heapArray[largerChild];
		index = largerChild;
	}
	heapArray[index] =  top;
}


/**************************
name: 
description： 
**************************/

#endif