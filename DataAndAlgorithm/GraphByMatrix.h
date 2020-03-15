//邻接矩阵实现图

#ifndef GRAPHBYMATRIX_H
#define GRAPHBYMATRIX_H
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#define MAX_GRAPH_NUM   20

class GraphByMatrix
{
public:
	GraphByMatrix()
	{
		m_nCurNum = 0;
		for (int i = 0; i < MAX_GRAPH_NUM; ++i)
			for (int j = 0; j < MAX_GRAPH_NUM; ++j)
				m_Matrix[i][j] = 0;
	}
	~GraphByMatrix()
	{
	}

	void addGraphData(char data)
	{
		m_graphData.push_back(data);
		m_vecVisied.push_back(false);
		m_nCurNum++;
	}

	void addEage(int nStart, int nEnd)
	{
		m_Matrix[nStart][nEnd] = 1;
	}

	void DisplayMatrix()
	{
		for (int i = 0; i < m_nCurNum; ++i)
		{
			for (int j = 0; j < m_nCurNum; ++j)
				std::cout << m_Matrix[i][j] << " ";
			std::cout << std::endl;
		}
	}

	//深度优先遍历
	void DFS()
	{
		if (m_nCurNum == 0)
		{
			std::cout << "Current Graph is Empty" << std::endl;
		}

		std::cout << "深度优先遍历： ";
		std::stack<int> gStack; //用堆栈记录访问下标顺序
		std::cout << m_graphData[0] << " ";
		m_vecVisied[0] = true;
		gStack.push(0);
		while (gStack.size() > 0)
		{
			int nNext = GetNextUnVisiedMatrix(gStack.top());
			if (nNext == -1)
			{
				gStack.pop();
			}
			else
			{
				std::cout << m_graphData[nNext] << " ";
				m_vecVisied[nNext] = true;
				gStack.push(nNext);
			}
		}

		for (auto it : m_vecVisied) it = false;

		std::cout << std::endl;
	}

	//广度优先算法
	void BFS()
	{
		if (m_nCurNum == 0)
		{
			std::cout << "Current Graph is Empty" << std::endl;
		}

		std::cout << "广度优先遍历： ";
		std::queue<int> gQueue; //用队列记录访问下标顺序
		std::cout << m_graphData[0] << " ";
		m_vecVisied[0] = true;
		gQueue.push(0);
		while (gQueue.size() > 0)
		{
			int nNextBeg = gQueue.front();
			int nCurNext = GetNextUnVisiedMatrix(nNextBeg);
			while (nCurNext != -1)
			{
				std::cout << m_graphData[nCurNext] << " ";
				m_vecVisied[nCurNext] = true;
				gQueue.push(nCurNext);
				nCurNext = GetNextUnVisiedMatrix(nNextBeg);
			}
			gQueue.pop();
		}
		for (auto it : m_vecVisied) it = false;

		std::cout << std::endl;
	}

	int GetNextUnVisiedMatrix(int nIndex)
	{
		for (int i = 0; i < m_nCurNum; ++i)
		{
			if (m_Matrix[nIndex][i] == 1 && m_vecVisied[i] == false)
			{
				return i;
			}
		}

		return -1;
	}

private:
	std::vector<char> m_graphData;
	int m_nCurNum;
	int m_Matrix[MAX_GRAPH_NUM][MAX_GRAPH_NUM];
	std::vector<bool> m_vecVisied;  //是否访问过
};

#endif