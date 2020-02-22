/*
 * @Coding: utf-8 \n
 * @Despcription:  \n
 * @Author: Suwen SP \n
 * @Date: 2019-05-16 09:05:37
 * @LastEditors: Suwen SP\n
 * @LastEditTime: 2019-05-19 09:32:00
 */
/* 1.����ͼ���ڽӾ�����ڽӱ�Ļ���ת���㷨��

2. �ֱ�����ڽӾ�����ڽӱ�洢ͼ������ͼ����Ⱥ͹�����ȱ����㷨(�ǵݹ�)

 3 ����AOV������������ */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXVEX = 100;
typedef char VertexType;
typedef int EdgeType;
//�ڽӾ���
typedef struct
{
	int num;
	EdgeType weight;
} ElemType; //������Ԫ�ص�����

typedef struct
{
	int edges[MAXVEX][MAXVEX]; //�ڽӾ���
	int numNodes, numEdges;
	ElemType vex[MAXVEX]; //��Ŷ�����Ϣ
} GraphAdjArray;

//�ڽӱ�
//�߱���
typedef struct EdgeNode
{
	int adjvex;
	EdgeType weight;
	struct EdgeNode *next;
} EdgeNode;
//�������
typedef struct VextexNode
{
	VertexType data;
	bool visited; //��ʾ�ýڵ��Ƿ񱻷���
	EdgeNode *firstedge;
} VetexNode, AdjList[MAXVEX];
//�ڽӱ�
typedef struct
{
	AdjList adjList;
	int numNodes, numEdges;
} GraphAdjList;

//�����ڽ��б�
//���� �߽��begin �߽��end Ȩ��
void CreateALGraph(GraphAdjList *Gp, int arr[][3], int numNodes, int numEdges)
{
	int i;
	EdgeNode *pe;
	Gp->numNodes = numNodes;
	Gp->numEdges = numEdges;
	//���붥����Ϣ�����߱���Ϊ0
	for (i = 0; i < Gp->numNodes; ++i)
	{
		Gp->adjList[i].data = i;
		Gp->adjList[i].firstedge = NULL;
	}
	//�����߱�
	for (i = 0; i < Gp->numEdges; ++i)
	{
		pe = (EdgeNode *)malloc(sizeof(EdgeNode));
		pe->adjvex = arr[i][1];
		pe->weight = arr[i][2];
		pe->next = Gp->adjList[arr[i][0]].firstedge;
		Gp->adjList[arr[i][0]].firstedge = pe;
		//�ظ�����Ĳ���
		pe = (EdgeNode *)malloc(sizeof(EdgeNode));
		pe->adjvex = arr[i][0];
		pe->weight = arr[i][2];
		pe->next = Gp->adjList[arr[i][1]].firstedge;
		Gp->adjList[arr[i][1]].firstedge = pe;
	}
}

//�����ڽӾ���
void CreateALArray(GraphAdjArray *Ga, int arr[][18], int numNodes, int numEdges)
{
	Ga->numEdges = numEdges;
	Ga->numNodes = numNodes;
	int i, j;
	//ֱ�ӽ��ڽӾ���д��edges�У�û���õ�ElemType vex[MAXVEX]
	for (i = 0; i < Ga->numNodes; ++i)
	{
		for (j = 0; j < Ga->numNodes; ++j)
			Ga->edges[i][j] = arr[i][j];
	}
}

//����ڽӱ�
void DispAdjList(GraphAdjList *Gp)
{
	int i;
	EdgeNode *p;
	for (i = 0; i < Gp->numNodes; ++i)
	{
		p = Gp->adjList[i].firstedge;
		cout << i << ": ";
		while (p != NULL)
		{
			cout << p->adjvex << " ";
			p = p->next;
		}
		cout << endl;
	}
}

//����ڽӾ���
void DispAdjArray(GraphAdjArray *Ga)
{
	int i, j;
	for (i = 0; i < Ga->numNodes; ++i)
	{
		for (j = 0; j < Ga->numNodes; ++j)
		{
			cout << Ga->edges[i][j] << " ";
		}
		cout << endl;
	}
}

//�ڽӾ���ת�����ڽӱ�
void ArratToList(GraphAdjArray *Ga, GraphAdjList *GatoGp)
{
	GatoGp->numEdges = Ga->numEdges;
	GatoGp->numNodes = Ga->numNodes;
	//���붥����Ϣ�����߱���Ϊ0
	int i, j;
	for (i = 0; i < GatoGp->numNodes; ++i)
	{
		GatoGp->adjList[i].data = i;
		GatoGp->adjList[i].firstedge = NULL;
	}
	EdgeNode *pe;
	pe = (EdgeNode *)malloc(sizeof(EdgeNode));
	for (i = 0; i < Ga->numNodes; ++i)
	{
		for (j = 0; j < Ga->numNodes; ++j)
		{
			if (Ga->edges[i][j] != 0)
			{
				pe = (EdgeNode *)malloc(sizeof(EdgeNode));
				pe->adjvex = j;
				pe->weight = Ga->edges[i][j];
				pe->next = GatoGp->adjList[i].firstedge;
				GatoGp->adjList[i].firstedge = pe;
			}
		}
	}
}
//�ڽӱ�ת�����ڽӾ���
void ListToArray(GraphAdjList *Gp, GraphAdjArray *GptoGa)
{
	EdgeNode *pe;
	GptoGa->numEdges = Gp->numEdges;
	GptoGa->numNodes = Gp->numNodes;
	int i, j;
	//�Ƚ��ڽӾ����Ԫ��ȫ����0
	for (i = 0; i < GptoGa->numNodes; ++i)
	{
		for (j = 0; j < GptoGa->numNodes; ++j)
			GptoGa->edges[i][j] = 0;
	}
	for (i = 0; i < Gp->numNodes; ++i)
	{
		pe = Gp->adjList[i].firstedge;
		while (pe != NULL)
		{
			GptoGa->edges[i][pe->adjvex] = pe->weight;
			pe = pe->next;
		}
	}
}
//��ʼ���ڵ�ķ���
void initVisted(GraphAdjList *Gp)
{
	for (int i = 0; i < Gp->numNodes; ++i)
	{
		Gp->adjList[i].visited = 0;
	}
}

//�ڽӱ�������������,��������浽vector��
void DFS(GraphAdjList *Gp, int start, vector<int> *vec)
{
	vec->push_back(start);
	cout << start << "��";
	Gp->adjList[start].visited = 1;
	EdgeNode *pe;
	pe = (EdgeNode *)malloc(sizeof(EdgeNode));
	pe = Gp->adjList[start].firstedge; //peָ���ͷ
	while (pe != NULL)
	{ //����Gp->adjList[start]�ı߱��ҵ�δ������
		if (!Gp->adjList[pe->adjvex].visited)
		{
			DFS(Gp, pe->adjvex, vec);
		}
		pe = pe->next;
	}
}
//�ڽӱ�Ĺ������
void BFS(GraphAdjList *Gp, int start, vector<int> *vec)
{
	queue<int> q;
	q.push(start);
	Gp->adjList[start].visited = 1;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		vec->push_back(current);
		EdgeNode *pe;
		pe = (EdgeNode *)malloc(sizeof(EdgeNode));
		pe = Gp->adjList[current].firstedge; //peָ��ͷ��㣬�����߱�
		while ((pe != NULL) && (!Gp->adjList[pe->adjvex].visited))
		{
			q.push(pe->adjvex);
			Gp->adjList[pe->adjvex].visited = 1;
			pe = pe->next;
		}
	}
}
int main()
{
	GraphAdjList Gp;
	int arr1[][3] = {{1, 0, 3},
					 {2, 0, 1},
					 {3, 0, 1},
					 {2, 1, 1},
					 {4, 1, 1},
					 {9, 1, 4},
					 {3, 2, 1},
					 {4, 2, 2},
					 {5, 2, 1},
					 {5, 3, 2},
					 {6, 3, 2},
					 {7, 3, 1},
					 {5, 4, 1},
					 {9, 4, 1},
					 {6, 5, 1},
					 {9, 5, 3},
					 {10, 5, 1},
					 {12, 5, 3},
					 {7, 6, 1},
					 {8, 6, 2},
					 {12, 6, 2},
					 {13, 6, 4},
					 {14, 6, 3},
					 {8, 7, 1},
					 {14, 8, 1},
					 {15, 8, 3},
					 {10, 9, 1},
					 {11, 9, 1},
					 {11, 10, 1},
					 {12, 10, 2},
					 {16, 11, 1},
					 {13, 12, 2},
					 {16, 12, 1},
					 {14, 13, 1},
					 {15, 13, 2},
					 {16, 13, 2},
					 {17, 13, 1},
					 {15, 14, 1},
					 {17, 15, 4},
					 {17, 16, 1}};
	CreateALGraph(&Gp, arr1, 18, 40);
	cout << "***********Gp**************" << endl;
	DispAdjList(&Gp);

	//����ڽӱ�
	GraphAdjArray Ga;
	int arr2[18][18] = {{0, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{3, 0, 1, 0, 1, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
						{1, 1, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{1, 0, 1, 0, 0, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 1, 2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 1, 2, 1, 0, 1, 0, 0, 3, 1, 0, 3, 0, 0, 0, 0, 0},
						{0, 0, 0, 2, 0, 1, 0, 1, 2, 0, 0, 0, 2, 4, 3, 0, 0, 0},
						{0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0},
						{0, 4, 0, 0, 1, 3, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 2, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0},
						{0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 1, 0},
						{0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 2, 0, 1, 2, 2, 1},
						{0, 0, 0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0},
						{0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 2, 1, 0, 0, 4},
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 1},
						{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 4, 1, 0}};
	CreateALArray(&Ga, arr2, 18, 40);
	DispAdjArray(&Ga);
	GraphAdjList GatoGp;
	ArratToList(&Ga, &GatoGp);
	cout << "********�ڽ�����ת��Ϊ�ڽӱ�Ľ��***********" << endl;
	DispAdjList(&GatoGp);
	GraphAdjArray GptoGa;
	ListToArray(&GatoGp, &GptoGa);
	cout << "********�ڽӱ�ת��Ϊ�ڽӾ���Ľ��***********" << endl;
	DispAdjArray(&GptoGa);

	//����Gp ��ȱ���
	vector<int> vec1 = {};
	initVisted(&Gp);
	cout << "�����ȱ����Ľ��" << endl;
	DFS(&Gp, 0, &vec1);
	//����Gp ��ȱ���
	cout << "�����ȱ����Ľ��" << endl;
	vector<int> vec2 = {};
	initVisted(&Gp);
	BFS(&Gp, 0, &vec2);

	return 0;
}