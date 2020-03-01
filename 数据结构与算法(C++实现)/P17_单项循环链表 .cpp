//改个名字
#include <iostream>
#include <list> //STL
#include "CircleList.h" //我做的

using namespace std;

int main()
{
	cout<< "测试..." << endl;

	cout<<"这是我的链表和迭代器： "<<endl;
	List<int> intList;

	intList.Insert(5);
	intList.Insert(15);
	intList.Insert(25);
	intList.Insert(35);

	ListIterator<int> li(intList);//建立一个ListIterator类的对象，用链表intList初始化
	if(li.NotNull())
	{
		cout<< *li.First();
		while(li.NextNotNull())
			cout<< " -> " << *li.Next();
		cout<< endl;
	}

	cout << "测试一下循环： " << endl;
	ListIterator<int> iter(intList);
	cout<< *iter.First() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;
	cout<< *iter.Next() << endl;

	return 0;
}