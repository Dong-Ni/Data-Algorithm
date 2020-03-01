#include <iostream>
#include <stack>
#include <queue>

#define MAX_VERTS 20

using namespace std;


class Vertex//顶点
{
public:
	Vertex(char lab)
	{
		Label = lab;
		wasVisited = false;
	}

//private:
	bool wasVisited;//记录顶点是否被访问过
	char Label;
};


class Graph
{
public:
	Graph();
	~Graph();
	void addVertex(char lab);//增加顶点
	void addEdge(int start, int end);//增加连线，增加边
	void printMatrix();//打印邻接矩阵

	void showVertex(int v);//显示下标为v的顶点

	void DFS();
	void BfS();

private:
	Vertex* vertexList[MAX_VERTS];//Vertex类型的指针数组，用来保存顶点
	int nVerts;//顶点数量
	int adjMat[MAX_VERTS][MAX_VERTS];//用来做邻阶矩阵的数组

	int getAdjUnvisitedVertex(int v);//获得和v相邻的还没有访问的下一个顶点,返回下标，没有则返回-1
};


/////////函数实现/////////

//BFS
void Graph::BfS()
{
	queue<int> gQueue;//保存下标
	vertexList[0]->wasVisited = true;
	showVertex(0);
	gQueue.push(0);//把第一个放进队列
	int vert1, vert2;
	while(gQueue.size() > 0)
	{
		vert1 = gQueue.front();//访问队列第一个
		gQueue.pop();//访问完就从队列里删掉
		vert2 = getAdjUnvisitedVertex(vert1);//和vert1相邻接的，未访问过的
		while(vert2 != -1)//相邻接的可能不止一个
		{
			vertexList[vert2]->wasVisited = true;
			showVertex(vert2);
			gQueue.push(vert2);//访问完一个就从队列里删掉那个
			vert2 = getAdjUnvisitedVertex(vert1);
		}
	}
	cout<< endl;

	for(int j=0; j<nVerts; j++)
		vertexList[j]->wasVisited = false;
}


//DFS
void Graph::DFS()
{
	stack<int> gStack;//保存下标
	vertexList[0]->wasVisited = true;
	showVertex(0);
	gStack.push(0);//把访问过的顶点都压入堆栈
	int v;
	while(gStack.size() > 0)
	{
		v = getAdjUnvisitedVertex(gStack.top());
		if(v == -1)
			gStack.pop();
		else
		{
			vertexList[v]->wasVisited = true;
			showVertex(v);
			gStack.push(v);
		}
	}
	cout<< endl;
	//搜索完一遍后，为了能重复进行
	for(int j=0; j<nVerts; j++)
		vertexList[j]->wasVisited = false;
}

//
int Graph::getAdjUnvisitedVertex(int v)
{
	for(int j=0; j<nVerts; j++)
	{
		//1.邻接矩阵对应值为1 2.还没被访问过
		if((adjMat[v][j] == 1) && (vertexList[j]->wasVisited == false))//两个条件
			return j;
	}
	return -1;
}

//
void Graph::showVertex(int v)
{
	cout<< vertexList[v]->Label << " ";
}

//构造函数
Graph::Graph()
{
	nVerts = 0;
	for(int i=0; i<MAX_VERTS; i++)
		for(int j=0; j<MAX_VERTS; j++)
			adjMat[i][j] = 0;
}

//增加顶点
void Graph::addVertex(char lab)
{
	vertexList[nVerts++] = new Vertex(lab);
}

//增加边
void Graph::addEdge(int start, int end)
{
	adjMat[start][end] = 1;
	adjMat[end][start] = 1;
}

//打印邻接矩阵
void Graph::printMatrix()
{
	for(int i=0; i<nVerts; i++)
	{
		for(int j=0; j<nVerts; j++)
			cout<< adjMat[i][j] << " ";
		cout<< endl;
	}
}

//析构函数
Graph::~Graph()
{
	for(int i=0; i<nVerts; i++)
		delete vertexList[i];
}



int main()
{
	cout<< "测试中。。。" << endl;

	Graph g;

	g.addVertex('A');//0,数组中位置
	g.addVertex('B');//1
	g.addVertex('C');//2
	g.addVertex('D');//3
	g.addVertex('E');//4

	//A-B添加一遍就好了
	g.addEdge(0, 1);//A-B,用数组下标来增加边，此处为在A,B间增加一条边
	g.addEdge(0,3);
	g.addEdge(1,0);
	g.addEdge(1,4);
	g.addEdge(2,4);
	g.addEdge(3,0);
	g.addEdge(3,4);//
	g.addEdge(4,1);
	g.addEdge(4,2);
	g.addEdge(4,3);
	
	g.printMatrix();

	cout<< "深度优先搜索的结果：" << endl;
	g.DFS();
	cout<< endl;

	cout<< "广度优先搜索的结果： " << endl;
	g.BfS();

	cout<< endl;

	system("pause");
	return 0;
}