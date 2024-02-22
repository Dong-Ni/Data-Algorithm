#include <iostream>
#include <vector>
#include <list>
#include <complex>
#include "DataAndAlgorithm/myTree.h"
#include "DataAndAlgorithm/BST.h"
#include "DataAndAlgorithm/MaxHeap.h"
#include "DataAndAlgorithm/GraphByMatrix.h"

using namespace std;

template<class T>
void CoutVector(T& t, int nNum)
{
	for (int i = 0; i < nNum; ++i)
	{
		cout << t[i] << " ";
	}

	cout << endl;
}

//ð������  ѡ���ķ����ұ�
void BubbleSort(int arr[], int nLen)
{
	for (int i = 0; i < nLen - 1; ++i)
	{
		for (int j = 0; j < nLen - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])swap(arr[j], arr[j + 1]);
		}
	}
}

//ѡ������ ��ѡ����ð�ݵ��Ż�  ���ٽ���������  ÿ��ѡ����С��
void SelectionSort(int arr[], int nLen)
{
	for (int i = 0; i < nLen - 1; ++i)
	{
		int nMin = i;  //��ǵ�ǰ��С���±�
		for (int j = i+1; j < nLen ; ++j)
		{
			if (arr[j] < arr[nMin]) nMin = j;
		}

		swap(arr[i], arr[nMin]);
	}
}

//�������ֲ���
int BinarySearch_I(int* arr, int nTar, int nLen)
{
	int nLeft = 0; 
	int nRight = nLen - 1;
	while (nLeft <= nRight)
	{
		int nMid = (nLeft + nRight/ 2);
		if (arr[nMid] == nTar) return nMid;
		else if (arr[nMid] > nTar) nRight = nMid - 1;
		else nLeft = nMid + 1;
	}

	return -1;
}
//�ݹ���ֲ���
int BinarySearch_R(int* arr, int nTar, int nLeft, int nRight)
{
	if (nLeft <= nRight)
	{
		int nMid = (nLeft + nRight) / 2;
		if (arr[nMid] == nTar) return nMid;
		else if (arr[nMid] > nTar) return BinarySearch_R(arr, nTar, nLeft, nMid-1);
		else return BinarySearch_R(arr, nTar, nMid+1, nRight);
	}
	else return -1;
}

//�ݹ��������  nBeg ->��һ��forѭ������ʼֵ
void Permutations(char* arr, int nBeg, int nEnd, vector<string> &vecRet)
{
	if (nBeg == nEnd)
	{
		vecRet.push_back(arr);
		return;
	}

	for (int i = nBeg; i <= nEnd; ++i)
	{
		swap(arr[nBeg], arr[i]);
		Permutations(arr, nBeg + 1, nEnd, vecRet);
		swap(arr[nBeg], arr[i]);
	}
}

//��������
void InsertSort(int* arr, int nNum)
{
	for (int i = 1; i < nNum; ++i)
	{
		int nTmp = arr[i];
		int nSel = i;
		while (nSel > 0 && arr[nSel - 1] > nTmp)
		{
			arr[nSel] = arr[nSel - 1];
			nSel--;
		}
		arr[nSel] = nTmp;
	}
}

//�ݹ��������
void QuickSort(int* arr, int nLeft, int nRight)
{
	if (nLeft < nRight)
	{
		int i = nLeft;
		int j = nRight + 1;  //�����Ϊʲô����Ҫ+1
		int nFlag = arr[i];  //��������������־λ

		//��nFlagС�ķ�����ߣ���ķ����ұ�
		do 
		{
			do i++; while (arr[i] < nFlag);
			do j--; while (arr[j] > nFlag);
			if (i < j)
			{
				swap(arr[i], arr[j]);
			}
		} while (i < j);
		swap(arr[nLeft], arr[j]); //�ƶ�ͷ�ϱ�׼����

		//�ݹ�
		QuickSort(arr, nLeft, j - 1);
		QuickSort(arr, j + 1, nRight);
	}
}

//�ݹ�鲢����
void Merge(int* arr, int* arrTmp, int nLeft, int nMid, int nRight)
{
	int nFirstTmp = nLeft;  // ��������ʼ
	int nSecondTmp = nMid +1; // ��������ʼ
	int nRst = 0;
	for (; nFirstTmp <= nMid && nSecondTmp <= nRight;)
	{
		if (arr[nFirstTmp] <= arr[nSecondTmp]) arrTmp[nRst++] = arr[nFirstTmp++];
		else arrTmp[nRst++] = arr[nSecondTmp++];
	}

	while (nFirstTmp <= nMid) arrTmp[nRst++] = arr[nFirstTmp++];
	while (nSecondTmp <= nRight) arrTmp[nRst++] = arr[nSecondTmp++];
	nRst = 0;
	while (nLeft <= nRight) arr[nLeft++] = arrTmp[nRst++];
}

void MergeSort(int* arr, int* arrTmp,int nLeft, int nRight)
{
	if (nLeft < nRight)
	{
		int nMid = (nLeft + nRight) / 2;
		MergeSort(arr, arrTmp, nLeft, nMid);  //���߹鲢
		MergeSort(arr, arrTmp, nMid+1, nRight); //�Ұ�߹鲢
		Merge(arr, arrTmp, nLeft, nMid, nRight);
	}
}

class MyNode
{
public:
	MyNode(int nData)
	{
		m_nData = nData;
		m_pNext = NULL;
	}

public:
	int m_nData;
	MyNode* m_pNext;
};

class MyList
{
public:

	MyList()
	{
		first = NULL;
	}

	//ͷ�巨
	void Insert(int nNum)
	{
		MyNode* nodeAdd = new MyNode(nNum);
		nodeAdd->m_pNext = first;
		first = nodeAdd;
	}

	//��ת
	void Reverse()
	{
		MyNode* p = first;  //�洢��Ҫ�ı�Ľڵ� ��һ����
		MyNode* q = NULL;   //�洢��ǰ��
		while (p)
		{
			MyNode* tmp = q;
			q = p;
			p = p->m_pNext;
			q->m_pNext = tmp;
		}

		first = q;
	}

	void Show()
	{
		MyNode* tmpBeg = first;
		while (tmpBeg != NULL)
		{
			cout << tmpBeg->m_nData;
			tmpBeg = tmpBeg->m_pNext;
			if (tmpBeg) cout << "->";
		}
	}

public:
	MyNode* first;
};

//��������
int MaxRadix(vector<int>& vecArr)  //�������λ����
{
	int nNum = 1;
	int nMax = 10;
	for (size_t i = 0; i < vecArr.size(); ++i)
	{
		while (vecArr[i] / nMax)
		{
			nMax *= 10;
			nNum++;
		}
	}

	return nNum;
}

void RadixSort(vector<int>& vecArr)
{
	int nMaxRadix = MaxRadix(vecArr);
	list<int> tmpList[10];
	int nSort, nFactor;
	size_t nNum;
	for (nSort = 0, nFactor = 1; nSort < nMaxRadix; ++nSort, nFactor *= 10)
	{
		//�Ѷ�Ӧλ�õ��������Ӧ�Ķ�����
		for (nNum = 0; nNum < vecArr.size(); ++nNum)
		{
			//nFactor����ȡ��λ��ʮλ�ȣ�%10,ȡģ����ȥ����λ,Ȼ���vecArr[nNum]�ŵ���Ӧ������
			tmpList[(vecArr[nNum] / nFactor) % 10].push_back(vecArr[nNum]);
		}

		//ȡ����ʱ�����е����Ż�������
		nNum = 0;
		for (int n = 0; n < 10; ++n)
		{
			while (!tmpList[n].empty())
			{
				vecArr[nNum++] = tmpList[n].front();
				tmpList[n].pop_front();
			}
		}
		cout << "the ==  " << nSort+1 << "  == time" << endl;
		CoutVector(vecArr, 10);
	}
}

int main()
{
	int arrTest[] = { 2, 4, 6, 5, 8, 0, 9, 7, 3, 1 };
	CoutVector(arrTest, 10);
	BubbleSort(arrTest, 10);
	cout << "after BubbleSort" << endl;
	CoutVector(arrTest, 10);

	cout << endl;
	cout << "====================" << endl;
	int arrTestsel[] = { 2, 4, 6, 5, 8, 0, 9, 7, 3, 1 };
	CoutVector(arrTestsel, 10);
	SelectionSort(arrTestsel, 10);
	cout << "after SelectionSort" << endl;
	CoutVector(arrTestsel, 10);

	cout << endl;
	cout << "====================" << endl;
	int arrTestFind[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int nRet = BinarySearch_I(arrTestFind, 711, 10);
	cout << "�������ֲ��� BinarySearch_I index = " << nRet << endl;
	nRet = BinarySearch_R(arrTestFind, 711, 0, 9);
	cout << "�ݹ���ֲ��� BinarySearch_R index = " << nRet << endl;

	cout << endl;
	cout << "====================" << endl;
	char chrTest[] = "abcd";
	vector<string> vecRetStr;
	Permutations(chrTest, 0, 3, vecRetStr);
	//for (auto it : vecRetStrcout << it << " , ";

	cout << endl;
	cout << "====================" << endl;
	int arrTestInsert[] = { 2, 4, 6, 5, 8, 0, 9, 7, 3, 1 };
	CoutVector(arrTestInsert, 10);
	InsertSort(arrTestInsert, 10);
	cout << "after InsertSort" << endl;
	CoutVector(arrTestInsert, 10);

	cout << endl;
	cout << "====================" << endl;
	int arrTestQuick[] = { 2, 4, 6, 5, 8, 0, 9, 7, 3, 1 };
	CoutVector(arrTestQuick, 10);
	QuickSort(arrTestQuick, 0, 9);
	cout << "after QuickSort" << endl;
	CoutVector(arrTestQuick, 10);

	cout << endl;
	cout << "====================" << endl;
	int arrTestMerge[] = { 2, 4, 6, 5, 8, 0, 9, 7, 3, 1 };
	CoutVector(arrTestMerge, 10);
	int *arrTmp = new int[10];
	MergeSort(arrTestMerge, arrTmp, 0, 9);
	cout << "after MergeSort" << endl;
	CoutVector(arrTestMerge, 10);


	cout << endl;
	cout << "====================" << endl;
	MyList listTest;
	listTest.Insert(0);
	listTest.Insert(1);
	listTest.Insert(2);
	listTest.Insert(3);
	listTest.Insert(4);
	listTest.Show();
	listTest.Reverse();
	cout << endl << "after Reverse." << endl;
	listTest.Show();


	cout << endl;
	cout << "====================" << endl;
	vector<int> vecNums = { 179, 208, 306, 93, 859, 984, 55, 9, 271, 33 };
	CoutVector(vecNums, vecNums.size());
	RadixSort(vecNums);
	cout << endl << "after RadixSort." << endl;
	CoutVector(vecNums, vecNums.size());

	cout << endl;
	cout << "====================" << endl;
	MyTree<char> tree;
	TreeNode<char> add, del, mul, eli, a, b, c, d, e;
	tree.root = &add;
	add.m_pLeft = &del;
	add.m_pRight = &e;
	add.data = '+';
	del.m_pLeft = &mul;
	del.m_pRight = &d;
	del.data = '-';
	mul.m_pLeft = &eli;
	mul.m_pRight = &c;
	mul.data = '*';
	eli.m_pLeft = &a;
	eli.m_pRight = &b;
	eli.data = '/';
	a.data = 'a';
	b.data = 'b';
	c.data = 'c';
	d.data = 'd';
	e.data = 'e';

	cout << "������� : ";
	tree.InOrder();
	cout << endl;
	cout << "ǰ����� : ";
	tree.PreOrder();
	cout << endl;
	cout << "������� : ";
	tree.PostOrder();
	cout << endl;
	cout << "������� : ";
	tree.LevelOrder();
	cout << endl;


	cout << endl;
	cout << "====================" << endl;
	BST<int> m;
	Element<int> elea, eleb, elec, eled, elee, elef, eleg, eleh, elej, elek, elel;
	elea.key = 5;
	eleb.key = 3;
	elec.key = 11;
	eled.key = 3;
	elee.key = 15;
	elef.key = 2;
	eleg.key = 8;
	eleh.key = 22;
	elej.key = 20;
	elek.key = 9;
	elel.key = 21;
	cout << m.Insert(elea) << endl;//a=5, ����root
	cout << m.Insert(eleb)<< endl;
	cout << m.Insert(elec)<< endl;
	cout << m.Insert(eled)<< endl;
	cout << m.Insert(elee)<< endl;
	cout << m.Insert(elef)<< endl;
	cout << m.Insert(eleg)<< endl;
	cout << m.Insert(eleh)<< endl;
	cout << m.Insert(elej)<< endl;
	cout << m.Insert(elek)<< endl;
	cout << m.Insert(elel)<< endl;
	m.DisPlay();
	BSTNode<int>* p = m.Search(elef);
	cout << "�ҵ����ǣ� " << p->data.key << endl;
	BSTNode<int>* p2 = m.SearchOrd(elee);
	cout << "�ҵ����ǣ� " << p2->data.key << endl;



	cout << endl;
	cout << "====================" << endl;
	MaxHeap<int> h(100);
	cout << h.IsEmpty()<< endl;
	h.Push(20);
	cout << h.Top() << endl;
	h.Push(30);
	cout << h.Top()<< endl;
	h.Push(15);
	cout << h.Top() << endl;
	h.Push(90);
	h.Push(35);
	cout << h.Top()<< endl;
	h.Pop();
	cout << h.Top()<< endl;
	h.Pop();
	cout << h.Top()<< endl;
	h.Pop();
	cout << h.Top()<< endl;
	h.Pop();
	cout << h.Top()<< endl;

	cout << endl;
	cout << "====================" << endl;
	GraphByMatrix graph;
	graph.addGraphData('A'); //0
	graph.addGraphData('B'); //1
	graph.addGraphData('C'); //2
	graph.addGraphData('D'); //3
	graph.addGraphData('E'); //4

	graph.addEage(0, 1);
	graph.addEage(0, 3);
	graph.addEage(1, 0);
	graph.addEage(1, 4);
	graph.addEage(2, 4);
	graph.addEage(3, 0);
	graph.addEage(3, 4);
	graph.addEage(4, 1);
	graph.addEage(4, 2);
	graph.addEage(4, 3);

	graph.DisplayMatrix();
	graph.DFS();
	graph.BFS();

	system("pause");
	return 0;

}