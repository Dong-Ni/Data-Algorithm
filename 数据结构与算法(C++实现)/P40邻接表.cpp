#include <iostream>
#include <list>

using namespace std;

class Vertex //方便使用各种各样的数据
{
public:
	char Label;
	Vertex(char lab) {Label = lab;}
};

////////重载////////
ostream& operator<<(ostream& out, const Vertex& v)//重载 <<
{
	cout<< v.Label;
	return out;
}

template<class T>
class Graph
{
public:
	Graph(const int vertices):n(vertices)
	{
		VertexList = new T*[];//指针数组,用来保存n个数组
		HeadNodes = new list<int>[n];//用来保存n个链表
		nVerts = 0;//开始一个都没有
	}
	~Graph()
	{
		delete[] VertexList;
		delete[] HeadNodes;
	}
	void addVertex(T* v);
	void addEdge(int start, int end);
	void printVertice();//打印所有顶点
	void printAdjList();//打印邻接表

private:
	T** VertexList;//一个指向T类型指针的指针 ？？？
	list<int>* HeadNodes;
	int n;//最多n个顶点
	int nVerts;//当前已有顶点数
};


//
template<class T>
void Graph<T>::addVertex(T* v)
{
	VertexList[nVerts++] = v;
}

//
template<class T>
void Graph<T>::addEdge(int start, int end)
{
	HeadNodes[start].push_back(end);

}

//
template<class T>
void Graph<T>::printVertice()
{
	for(int i=0; i<nVerts; i++)
		cout<< *VertexList[i] << " ";
	cout<< endl;
}

//
template<class T>
void Graph<T>::printAdjList()
{
	for(int i=0; i<nVerts; i++)
	{
		cout<< i << "->";
		for(list<int>::iterator iter = HeadNodes[i].begin(); iter!=HeadNodes[i].end(); ++iter)
			cout<< *iter << "->";
		cout<< "end" << endl;
	}
}


int main()
{
	cout<< "测试中。。。" << endl;

	////不使用Vertex类
	//Graph<char> g(5);
	//char a = 'A';
	//char b = 'B';
	//char c = 'C';
	//char d = 'D';
	//char e = 'E';

	//使用Vertex类
	Graph<Vertex> g(5);
	Vertex a('A');
	Vertex b('B');
	Vertex c('C');
	Vertex d('D');
	Vertex e('E');



	g.addVertex(&a);
	g.addVertex(&b);
	g.addVertex(&c);
	g.addVertex(&d);
	g.addVertex(&e);

	g.printVertice();

	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(1,0);
	g.addEdge(1,4);
	g.addEdge(2,4);
	g.addEdge(3,0);
	g.addEdge(3,4);
	g.addEdge(4,1);
	g.addEdge(4,2);
	g.addEdge(4,3);

	g.printAdjList();

	system("pause");
	return 0;
}