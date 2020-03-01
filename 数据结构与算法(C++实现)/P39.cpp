#include <iostream>

#define MAX_VERTS 20

using namespace std;


class Vertex//顶点
{
public:
	Vertex(char lab){ Label = lab;}

private:
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
private:
	Vertex* vertexList[MAX_VERTS];//Vertex类型的指针数组，用来保存顶点
	int nVerts;//顶点数量
	int adjMat[MAX_VERTS][MAX_VERTS];//用来做邻阶矩阵的数组
};

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


	system("pause");
	return 0;
}