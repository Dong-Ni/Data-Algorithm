#ifndef QUEUELINE_H
#define QUEUELINE_H


template<class T>
class Queue
{
public:
	Queue();
	~Queue();//!!!!!!把内存全部清空，防止内存泄漏！！！！！！

	bool isEmpty() const;
	const T& getFront() const;//从队首取数据，不删除
	void enqueue(const T& x);//入队
	T dequeue();//出队,删除队首
	void makeEmpty();

private:
	struct ListNode//Queue内嵌套的一个结构体,也可写成类
	{
		T element;
		ListNode *next;

		ListNode(const T& theElement, ListNode *n = 0):element(theElement), next(n){}

	};

	ListNode *front;
	ListNode *back;
};


/******函数实现******/
/*******************/
/*******************/

template<class T>
Queue<T>::Queue()
{
	front = back = 0;
}


template<class T>
Queue<T>::~Queue()
{
	makeEmpty();
}

template<class T>
void Queue<T>::makeEmpty()
{
	while(!isEmpty())
		dequeue();
}


template<class T>
bool Queue<T>::isEmpty() const
{
	return front == 0;
}


template<class T>
const T& Queue<T>::getFront() const
{
	if(isEmpty())
		throw "queue is empty.";
	return front->element;
}


template<class T>
void Queue<T>::enqueue(const T& x)
{
	if(isEmpty())
		back = front = new ListNode(x);//指针默认为0
	else
		//1.
		//back->next = new ListNode(x);
		//back = back->next;

		//2. 
		back = back->next = new ListNode(x);//******为什么用1时，入队以后调用getfront无输出？？？
}


template<class T>
T Queue<T>::dequeue()
{
	T frontItem = getFront();

	ListNode *old = front;
	front = front->next;

	delete old; //对应入队时的new
	return frontItem;
}

#endif
