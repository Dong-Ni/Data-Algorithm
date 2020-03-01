#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

template<class T> class LinkedStack;


template<class T> 
class ChainNode
{
	friend class LinkedStack<T>;
private:
	ChainNode(const T& theData, ChainNode *n = 0):data(theData), link(n){}
	T data;
	ChainNode<T> *link;
};


template<class T>
class LinkedStack
{
public:
	LinkedStack():top(0) {}
	~LinkedStack(){ MakeEmpty(); }
	bool IsEmpty() const;
	T& Top() const;
	void Push(const T& e);
	void Pop();


	void MakeEmpty();
private:
	ChainNode<T> *top;
};


/******函数实现******/
/*******************/
/*******************/

template<class T>
void LinkedStack<T>::MakeEmpty()
{
	while(!IsEmpty())
		Pop();
}


template<class T>
bool LinkedStack<T>::IsEmpty() const
{
	return top == 0;
}


template<class T>
T& LinkedStack<T>::Top() const
{
	if(this-> IsEmpty())
		throw "stack is empty";
	return top->data;
}


template<class T>
void LinkedStack<T>::Push(const T &e)
{
	top = new ChainNode<T>(e, top);
}


template<class T>
void LinkedStack<T>::Pop()
{
	if(this->IsEmpty())
		throw "stack is empty. cannot delete.";
	ChainNode<T> *delNode = top;
	top = top->link;
	delete delNode;   //对应上面的new
}


#endif