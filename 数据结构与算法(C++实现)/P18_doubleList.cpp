#include <iostream>

using namespace std;

class DblList;//前置声明

class DblListNode
{
	friend class DblList;
public:
	int data;
	DblListNode *llink, *rlink;
};

class DblList
{
public:
	DblList()
	{
		first = new DblListNode();
		first->llink = first->rlink = first;
	}
	void Insert(DblListNode*, DblListNode*);
	void Delete(DblListNode*);

	DblListNode* getfirst()
	{
		return first;
	}
private:
	DblListNode *first;
};


void DblList::Insert(DblListNode *p, DblListNode *x) //将新节点p插入到节点x的后面(右面）
{
	p->llink = x;
	p->rlink = x->rlink;
	x->rlink->llink = p;
	x->rlink = p;
}


void DblList::Delete(DblListNode *x)
{
	if(x == first)
		cout << "deletion of head node is not permitted." << endl;
	else
	{
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
		//delete x;   //delete和new对应
	}
}


int main()
{
	cout<< "Hell shuangxianglianbiao!" << endl;

	DblList intList;
	DblListNode node1, node2, node3, node4, node5;
	node1.data = 10;
	node2.data = 20;
	node3.data = 30;
	node4.data = 40;
	node5.data = 50;

	intList.Insert(&node1, intList.getfirst());
	intList.Insert(&node2, intList.getfirst());
	intList.Insert(&node3, intList.getfirst());
	intList.Insert(&node4, intList.getfirst());
	intList.Insert(&node5, intList.getfirst());
	intList.Delete(&node3);

	cout << intList.getfirst()->rlink->data << endl;
	cout << intList.getfirst()->rlink->rlink->data << endl;
	cout << intList.getfirst()->rlink->rlink->rlink->data << endl;
	cout << intList.getfirst()->rlink->rlink->rlink->rlink->data << endl;
	cout << intList.getfirst()->rlink->rlink->rlink->rlink->rlink->data << endl;

	return 0;
}