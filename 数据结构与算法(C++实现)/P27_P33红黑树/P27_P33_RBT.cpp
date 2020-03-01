#include <iostream>
#include "RedBlackTree.h"

using namespace std;

int main()
{
	cout<< "测试。。。" << endl;
	const int NEG_INF = -9999;
	RedBlackTree<int> t(NEG_INF);

	//t.insert(30);
	//t.insert(15);
	//t.insert(70);
	//t.insert(20);

	//cout<< t.header->right->element << endl;
	//cout<< t.header->right->left->element << endl;
	//cout<< t.header->right->right->element << endl;
	//cout<< t.header->right->left->right->element << endl; //20

	//cout<< "向右转：" << endl;
	//t.rotateWithLeftChild(t.header->right);
	//cout<< t.header->right->element << endl;
	//cout<< t.header->right->right->left->element << endl;

	//cout<< "向左转: " << endl;
	//t.rotateWithRightChild(t.header->right);
	//cout<< t.header->right->element << endl;
	//cout<< t.header->right->left->element << endl;
	//cout<< t.header->right->right->element << endl;
	//cout<< t.header->right->left->right->element << endl;


	//t.insert(12);
	//t.insert(16);
	//t.insert(8);
	//t.insert(10);
	//t.insert(4);
	//t.insert(14);
	//t.insert(2);
	//t.insert(6);
	//t.insert(5);

	//cout<< t.header->right->left->left->right->left->element << endl;
	//cout<< t.header->right->left->element << endl;
	//t.doubleRotateWithLeftChild(t.header->right->left);
	//cout<< t.header->right->left->element << endl;
	//cout<< t.header->right->left->left->right->element << endl;


	t.insert(50);
	t.insert(40);
	t.insert(30);
	cout<< t.header->right->element << endl;

	if(!t.isEmpty()) 
		cout<< "红黑树不是空的" << endl;

	t.makeEmpty();
	if(t.isEmpty()) 
		cout<< "红黑树是空的" << endl;
	//cout<< t.header->right->element << endl;

	t.insert(200);
	t.insert(100);
	t.insert(90);
	t.insert(50);
	t.insert(80);
	t.insert(70);
	t.insert(60);
	
	if(t.findMin().get() == 50)
		cout<< "找到了最小的数" << endl;
	
	cout<< "最大的： " << t.findMax().get() << endl;

	Cref<int> r = t.find(80);
	if(r.isNull())
		cout<< "没找到！" << endl;
	else
		cout<< "找到: " << r.get() << endl;

	/*system("pause");*/
	return 0;
}