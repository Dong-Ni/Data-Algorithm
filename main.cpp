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

//ð������  ѡ���ķ����ұ�
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
		int nMid = (nLeft + nRight) / 2;
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
	cout << "�������ֲ��� BinarySearch_I index = " << nRet << endl;
	nRet = BinarySearch_R(arrTestFind, 711, 0, 9);
	cout << "�ݹ���ֲ��� BinarySearch_R index = " << nRet << endl;

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

	cout << endl;
	cout << "====================" << endl;
	int arrTestQuick[] = { 2, 4, 6, 5, 8, 0, 9, 7, 3, 1 };
	CoutArr(arrTestQuick, 10);
	QuickSort(arrTestQuick, 0, 9);
	cout << "after QuickSort" << endl;
	CoutArr(arrTestQuick, 10);

	cout << endl;
	cout << "====================" << endl;
	int arrTestMerge[] = { 2, 4, 6, 5, 8, 0, 9, 7, 3, 1 };
	CoutArr(arrTestMerge, 10);
	int *arrTmp = new int[10];
	MergeSort(arrTestMerge, arrTmp, 0, 9);
	cout << "after MergeSort" << endl;
	CoutArr(arrTestMerge, 10);


	system("pause");
	return 0;

}