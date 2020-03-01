#include <iostream>
#include <list>

using namespace std;

void PrintListContents(const list<int>& listInput);

int main()
{
	list<int> a;
	
	a.push_back(10);
	a.push_back(104);
	a.push_back(25);
	a.push_back(38);
	a.push_back(4);

	PrintListContents(a);

	a.reverse();//·´×ª
	PrintListContents(a);

	a.sort();//ÅÅÐò
	PrintListContents(a);

	a.reverse();
	PrintListContents(a);


	return 0;
}


void PrintListContents(const list<int>& listInput)
{
	cout<< endl;
	cout<< "{ ";
	list<int>::const_iterator iter;
	for(iter=listInput.begin(); iter!=listInput.end(); ++iter)
		cout<< *iter << " ";
	cout<< "}" << endl;
}