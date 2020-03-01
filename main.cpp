#include <iostream>
#include <vector>
#include <list>

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

//冒泡排序  选最大的放在右边
void BubbleSort(int arr[], int nLen)
{
	for (int i = 0; i < nLen - 1; ++i)
	{
		for (int j = 0; j < nLen - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}

//选择排序 （选择是冒泡的优化  减少交换次数）  每次选择最小的
void SelectionSort(int arr[], int nLen)
{
	for (int i = 0; i < nLen - 1; ++i)
	{
		int nMin = i;  //标记当前最小的下标
		for (int j = i+1; j < nLen ; ++j)
		{
			if (arr[j] < arr[nMin]) nMin = j;
		}

		swap(arr[i], arr[nMin]);
	}
}

//迭代二分查找
int BinarySearch_I(int* arr, int nTar, int nLen)
{
	int nLeft = 0; 
	int nRight = nLen - 1;
	while (nLeft <= nRight)
	{
		int nMid = (nLeft + nRight) / 2;
		if (arr[nMid] == nTar) return nMid;
		else if (arr[nMid] > nTar) nRight = nMid - 1;
		else nLeft = nMid + 1;
	}

	return -1;
}
//递归二分查找
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

//递归排列组合  nBeg ->下一次for循环的起始值
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

//插入排序
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

//递归快速排序
void QuickSort(int* arr, int nLeft, int nRight)
{
	if (nLeft < nRight)
	{
		int i = nLeft;
		int j = nRight + 1;  //分清楚为什么这里要+1
		int nFlag = arr[i];  //用最左侧的数做标志位

		//比nFlag小的放在左边，大的放在右边
		do 
		{
			do i++; while (arr[i] < nFlag);
			do j--; while (arr[j] > nFlag);
			if (i < j)
			{
				swap(arr[i], arr[j]);
			}
		} while (i < j);
		swap(arr[nLeft], arr[j]); //移动头上标准数据

		//递归
		QuickSort(arr, nLeft, j - 1);
		QuickSort(arr, j + 1, nRight);
	}
}

//递归归并排序
void Merge(int* arr, int* arrTmp, int nLeft, int nMid, int nRight)
{
	int nFirstTmp = nLeft;  // 左子序起始
	int nSecondTmp = nMid +1; // 右子序起始
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
		MergeSort(arr, arrTmp, nLeft, nMid);  //左半边归并
		MergeSort(arr, arrTmp, nMid+1, nRight); //右半边归并
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

	//头插法
	void Insert(int nNum)
	{
		MyNode* nodeAdd = new MyNode(nNum);
		nodeAdd->m_pNext = first;
		first = nodeAdd;
	}

	//反转
	void Reverse()
	{
		MyNode* p = first;  //存储需要改变的节点 下一个点
		MyNode* q = NULL;   //存储当前点
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

//基数排序
int MaxRadix(vector<int>& vecArr)  //返回最高位个数
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
		//把对应位置的数插入对应的队列中
		for (nNum = 0; nNum < vecArr.size(); ++nNum)
		{
			//nFactor，提取个位，十位等，%10,取模可以去除高位,然后把vecArr[nNum]放到对应的链表
			tmpList[(vecArr[nNum] / nFactor) % 10].push_back(vecArr[nNum]);
		}

		//取出临时队列中的数放回数组中
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
	cout << "迭代二分查找 BinarySearch_I index = " << nRet << endl;
	nRet = BinarySearch_R(arrTestFind, 711, 0, 9);
	cout << "递归二分查找 BinarySearch_R index = " << nRet << endl;

	cout << endl;
	cout << "====================" << endl;
	char chrTest[] = "abcd";
	vector<string> vecRetStr;
	Permutations(chrTest, 0, 3, vecRetStr);
	for (auto it : vecRetStr) cout << it << " , ";

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

	system("pause");
	return 0;

}