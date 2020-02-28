#include <iostream>
#include <vector>

using namespace std;

void CoutArr(int arr[], int nLen)
{
	for (int i = 0; i < nLen; ++i)
	{
		cout << arr[i] << " ";
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

int main()
{
	int arrTest[] = { 2, 4, 6, 5, 8, 0, 9, 7, 3, 1 };
	CoutArr(arrTest, 10);
	BubbleSort(arrTest, 10);
	cout << "after BubbleSort" << endl;
	CoutArr(arrTest, 10);

	cout << endl;
	cout << "====================" << endl;
	int arrTestsel[] = { 2, 4, 6, 5, 8, 0, 9, 7, 3, 1 };
	CoutArr(arrTestsel, 10);
	SelectionSort(arrTestsel, 10);
	cout << "after SelectionSort" << endl;
	CoutArr(arrTestsel, 10);

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
	CoutArr(arrTestInsert, 10);
	InsertSort(arrTestInsert, 10);
	cout << "after InsertSort" << endl;
	CoutArr(arrTestInsert, 10);
	system("pause");
	return 0;

}