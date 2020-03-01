#include <iostream>
#include "btree.h"

using namespace std;

int main()
{
	BinaryTree<char> tree;
	TreeNode<char> add, sub, mul, div, a, b, c, d, e;

	add.data = '+';
	sub.data = '-';
	mul.data = '*';
	div.data = '/';
	a.data = 'A';
	b.data = 'B';
	c.data = 'C';
	d.data = 'D';
	e.data = 'E';

	tree.root = &add;
	add.leftChild = &sub;
	add.rightChild = &e;
	sub.leftChild = &mul;
	sub.rightChild = &d;
	mul.leftChild = &div;
	mul.rightChild = &c;
	div.leftChild = &a;
	div.rightChild = &b;

	cout<< "ǰ�����: ";
	tree.PreOrder();//ǰ�����
	cout<< endl;

	cout<< "�������: " ;
	tree.InOrder();//�������
	cout<< endl;

	cout<< "�������: " ;
	tree.PostOrder();//�������
	cout<< endl;

	cout<< "�������: " ;
	tree.LevelOrder();//�������
	cout<< endl;

	return 0;
}