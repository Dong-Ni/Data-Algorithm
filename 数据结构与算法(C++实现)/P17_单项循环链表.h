#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include <iostream>

//循环链表
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
	ListNode(T element);//只能由友元类来调用 //有参数的构造函数
	ListNode(){}//无参数的构造函数
};


template<class T>
class List
{
	friend class ListIterator<T>;
public:
	//List(){ first = 0;}
	List(){ first = new ListNode<T>; first->link = first; } //*******带表头结构的
	void Insert(T);
	void Delete(T);
private:
	ListNode<T> *first;
};


template<class T>
class ListIterator
{
public:
	ListIterator(const List<T>& L):list(L), current(L.first->link){}  //******不要忘了{}
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


/******插入：从后面******/
template<class T>
void List<T>::Insert(T k)
{
	ListNode<T> *newnode = new ListNode<T>(k); //k是存放在节点里的数据
	newnode->link = first->link;
	first->link = newnode;
}


template<class T>
void List<T>::Delete(T k)
{
	//ListNode<T> *previous = 0;//被删的前一个
	ListNode<T> *previous = first;//改成first
	ListNode<T> *current;
	for(current = first; (current!=first) && (current->data != k);)
	{
		previous =current;
		current = current->link;
	}
	if(current != first)//找到了
	{
		/*if(previous)
			previous->link = current->link;
		else
			first = first->link;*/
		previous->link = current->link;
		delete current;
	}
	else
		std::cout << "没有这个值" << std::endl;

}



template<class T>
bool ListIterator<T>::NotNull()
{
	if(current != list.first) 
		return true;
	else
		return false;
}


template<class T>
bool ListIterator<T> ::NextNotNull()
{
	if(current->link != list.first)
		return true;
	else
		return false;
}


template<class T>
T* ListIterator<T>::First()
{
	if(current != list.first)
		return &current->data;//****返回节点里数据 的指针
	else
		return 0;
}


template<class T>
T* ListIterator<T>::Next()
{
	current = current->link;
	if(current == list.first)
		current = current->link;
	return &current->data;
}


#endif