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

	cout<< "前序遍历: ";
	tree.PreOrder();//前序遍历
	cout<< endl;

	cout<< "中序遍历: " ;
	tree.InOrder();//中序遍历
	cout<< endl;

	cout<< "后序遍历: " ;
	tree.PostOrder();//后序遍历
	cout<< endl;

	cout<< "层序遍历: " ;
	tree.LevelOrder();//层序遍历
	cout<< endl;

	return 0;
}