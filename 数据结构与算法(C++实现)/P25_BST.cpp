//测试

#include <iostream>
#include "BST.h"

using namespace std;


int main()
{
	cout<< "测试。。。" << endl << endl;

	BST<int> m;
	Element<int> a, b, c, d, e, f, g, h, j, k, l;
	a.key = 5;
	b.key = 3;
	c.key = 11;
	d.key = 3;
	e.key = 15;
	f.key = 2;
	g.key = 8;
	h.key = 22;
	k.key = 20;
	l.key = 9;

	cout<< m.Insert(a) << endl;//a=5, 就是root
	cout<< m.Insert(b) << endl;
	cout<< m.Insert(c) << endl;
	cout<< m.Insert(d) << endl;
	cout<< m.Insert(e) << endl;
	cout<< m.Insert(f) << endl;
	cout<< m.Insert(g) << endl;
	cout<< m.Insert(h) << endl;
	cout<< m.Insert(j) << endl;
	cout<< m.Insert(k) << endl;
	cout<< m.Insert(l) << endl;
	m.display();


	BstNode<int> *p = m.Search(f);
	cout<< "找到的是： " << p->getdata().key << endl;

	BstNode<int> *p2 = m.IterSearch(e);
	cout<< "找到的是： " << p2->getdata().key << endl;

	
	return 0;
}