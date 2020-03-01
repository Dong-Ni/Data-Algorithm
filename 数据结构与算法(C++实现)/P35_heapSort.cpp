#include <iostream>
#include "heapSort.h"

using namespace std;

int main()
{
	cout<< "²âÊÔÖÐ......" << endl;
	
	MaxHeap<int> h(100);

	int arr[] = {62, 3, 90, 27, 33, 8, 12, 9, 43, 66};

	for(int i=0; i<10; i++)
		h.Push(arr[i]);
	for(int i=0; i<10; i++)
	{
		arr[9-i] = h.Top();
		h.Pop();
	}
	for(int i=0; i<10; i++)
		cout<< arr[i] << " ";
	cout<< endl;

	system("pause");
	return 0;
}