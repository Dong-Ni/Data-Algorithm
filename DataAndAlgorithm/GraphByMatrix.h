//¡⁄Ω”æÿ’Û µœ÷Õº

#ifndef GRAPHBYMATRIX_H
#define GRAPHBYMATRIX_H
#include <iostream>

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
		for (int i = 0; i < m_nCurNum; ++i)
			delete m_graphData[i];
	}

	void addGraphData(char data)
	{
		char* addData = new char;
		addData = &data;
		m_graphData[m_nCurNum++] = addData;
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

private:
	char* m_graphData[MAX_GRAPH_NUM];
	int m_nCurNum;
	int m_Matrix[MAX_GRAPH_NUM][MAX_GRAPH_NUM];
};

#endif