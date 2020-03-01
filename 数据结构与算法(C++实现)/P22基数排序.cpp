#include <iostream>
#include <list>

using namespace std;

int maxdigit(int data[], int n)//计算最大的数是几位
{
	int d = 1;
	int p = 10;
	for(int i=0; i<n; ++i)
	{
		while(data[i] >= p)
		{
			p *= 10;
			++d;
		}
	}
	return d;
}


void radixsort(int data[], int n)
{
	int digits = maxdigit(data, n);
	list<int> lists[10];//生成十个链表
	int d, j, k, factor;
	for(d=1,factor=1; d<=digits; factor*=10,d++)
	{
		for(j=0; j<n; j++)//1.把数组里的数复制到链表里
		{
			///factor，提取个位，十位等，%10,取模可以去除高位,然后把data[j]放到对应的链表
			lists[ (data[j]/factor) % 10].push_back(data[j]); 
		}
		for(j=k=0; j<10; j++)//2.按顺序把链表里的数放到原数组里
		{
			while(!lists[j].empty())//当链表还有数时，就一直取
			{
				data[k++] = lists[j].front();//k++好灵活
				lists[j].pop_front();//去完后，链表里要删掉这个数
			}
		}
		for(int m=0; m<10; m++)
			cout<< data[m] << " " ;
		cout<< endl;
	}
}

int main()
{
	cout<< "hello" <<endl;


	int data[10] = {179, 208, 306, 93, 859, 984, 55, 9, 271, 33};
	radixsort(data, 10);

	cout<< "排序后" << endl;
	for(int i=0; i<10; i++)
		cout<< data[i] << " " ;

	cout<< endl;


	system("pause");
	return 0;
}