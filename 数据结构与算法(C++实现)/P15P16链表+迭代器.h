#ifndef LIST_H
#define LIST_H

#include <iostream>


template<class T> class List;
template<class T> class ListIterator;//*********定义友元不要忘了前置声明

template<class T>
class ListNode
{
friend  class List<T>;
friend class ListIterator<T>;

private:
	T data;
	ListNode *link;
	ListNode(T element);//只能由友元类来调用
};


template<class T>
class List
{
	friend class ListIterator<T>;
public:
	List(){ first = 0;}
	void Insert(T);
	void Delete(T);
	void Invert();
	void Concatenate(List<T>);
	void Show();//测试用
	

private:
	ListNode<T> *first;
};


template<class T>
class ListIterator
{
public:
	ListIterator(const List<T>& L):list(L), current(L.first){}  //*****不要忘了{}
	bool NotNull();//当前节点是否空
	bool NextNotNull();//当前节点的下一节点是否空
	T* First();
	T* Next();
private:
	const List<T> &list;
	ListNode<T>* current;

};




template<class T>
ListNode<T>::ListNode(T element)
{
	data = element;
	link = 0;
}


/******插入：从前面******/
template<class T>
void List<T>::Insert(T k)
{
	ListNode<T> *newnode = new ListNode<T>(k); //k是存放在节点里的数据
	newnode->link = first;
	first = newnode;
}


template<class T>
void List<T>::Delete(T k)
{
	ListNode<T> *previous = 0;//被删的前一个
	ListNode<T> *current;
	for(current = first; current && current->data != k;)
	{
		previous =current;
		current = current->link;
	}
	if(current)//找到了
	{
		if(previous)
			previous->link = current->link;
		else
			first = first->link;
		delete current;
	}
	else
		std::cout << "没有这个值" << std::endl;

}


template<class T>
void List<T>::Invert()
{
	ListNode<T> *p = first, *q = 0;
	while(p)
	{
		ListNode<T> *r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	first = q;
}


template<class T>
void List<T>::Concatenate(List<T> b)//b接在后面
{
	if(!first){ first = b.first; return;}
	if(b.first)
	{
		ListNode<T> *p;
		for(p=first; p->link; p=p->link) {;}//循环内容为空
		p->link = b.first;
	}
}




//Show
template<class T>
void List<T>::Show()
{
	for(ListNode<T> *current = first; current; current=current->link)
	{
		std::cout<< current->data;
		if(current->link)
			std::cout<< " -> ";
	}
	std::cout<< std::endl;
}



template<class T>
bool ListIterator<T>::NotNull()
{
	if(current) 
		return true;
	else
		return false;
}


template<class T>
bool ListIterator<T> ::NextNotNull()
{
	if(current && current->link)
		return true;
	else
		return false;
}


template<class T>
T* ListIterator<T>::First()
{
	if(list.first)
		return &list.first->data;//****返回节点里数据 的指针
	else
		return 0;
}


template<class T>
T* ListIterator<T>::Next()
{
	if(current)
	{
		current = current->link;
		return &current->data;
	}
	return 0;
}


#endif