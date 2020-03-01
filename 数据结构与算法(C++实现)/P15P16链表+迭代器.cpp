//改个名字
#include <iostream>
#include <list> //STL
#include "List.h"//我做的

using namespace std;

int main()
{
	cout<< "测试" << endl;

	cout << "这是标准C++ STL 中的链表和迭代器：" << endl;
	list<int> listIntegers;
	listIntegers.push_front(5);
	listIntegers.push_front(15);
	listIntegers.push_front(25);
	listIntegers.push_front(35);

	list<int>::iterator i = listIntegers.begin();
	while(i != listIntegers.end())
	{
		cout<< *i << " -> ";
		++i;
	}
	cout<< endl << endl;


	
	cout<<" 这是我的链表和迭代器： "<<endl;
	List<int> intList;

	intList.Insert(5);
	intList.Insert(15);
	intList.Insert(25);
	intList.Insert(35);
	intList.Show();

	intList.Delete(21);
	intList.Show();

	intList.Invert();
	intList.Show();
	intList.Invert();
	intList.Show();

	List<char> charList;
	charList.Insert('a');
	charList.Insert('b');
	charList.Insert('c');
	charList.Show();
	charList.Invert();
	charList.Show();

	List<char> char2List;
	char2List.Insert('a');
	char2List.Insert('b');
	char2List.Insert('c');
	char2List.Show();
	char2List.Invert();
	char2List.Show();

	charList.Concatenate(char2List);
	charList.Show();

	cout<< endl << endl;
	ListIterator<char> li(charList);//建立一个ListIterator类的对象，用链表charList初始化
	if(li.NotNull())
	{
		cout<< *li.First() * 10; //*********迭代的过程中可以对数据进行任意处理，迭代器的优势！！！
		while(li.NextNotNull())
			cout<< " -> " << *li.Next() * 10;
		cout<< endl;
	}

	return 0;
}