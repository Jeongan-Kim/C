#include <iostream>

// 한방향으로 가다가 길이 막히면 다시 직전으로 돌아와서 안간 곳 다시 파기
// 불필요한 경우를 차단하지 못 하므로 백트래킹보다는 경우를 줄일 수 없음

/*
	노드(정점을 나타냄, 데이터가 들어있음), 간선(노드를 연결함)으로 그려진 그래프가 있을 때
	이 간선을 따라 들어갈 수 있는 곳까지 들어가서 탐색.
	해당 노드들을 방문했는지 안했는지 체크하면서 탐색.
*/

using namespace std;

template<typename T>
class Graph
{
public:
	struct Node;

	struct Edge //간선
	{
		Node* start = NULL; //간선 시작점
		Node* Target = NULL; //간선 도착지
		Edge* Next = NULL; // 다음 간선에 대한 정보
	};

	struct Node
	{
		T data;
		int Index = -1;

		Node* Next = NULL; //간선
		Edge* Edge = NULL;

		bool Visited = false; //방문 여부
	};

private:
	Node* Head = NULL; //노드 가장 첫번째 것
	int Count = 0;

public:
	static Edge* CreateEdge(Node* start, Node* target) //시작 도착 노드를 매개변수로 받아 간선 생성
	{
		Edge* edge = new Edge();
		edge->start = start;
		edge->Target = target;

		return edge;
	}

	static Node* CreateNode(T data) //데이터를 받아 노드 생성
	{
		Node* node = new Node();
		node->Data = data;

		return node;
	}

public:
	void AddNode(Node* node) //그래프에 노드 추가
	{
		Node* nodeList = Head; //노드 구조체 객체 생성

		if (nodeList != NULL)
		{
			while (nodeList->Next != NULL)//남은 노드들이 없을 때까지 추가
			{
				nodeList = nodeList->Next;
			}

			nodeList->Next = node;
		}
		else
		{
			Head = node;
		}

		node->Index = Count++;
	}

	void AddEdge(Node* node, Edge* edge)
	{
		if (node->Edge != NULL)
		{
			Edge* edgeList = node->Edge;

			while (edgeList->Next != NULL)
			{
				edgeList = edgeList->Next;
			}

			edgeList->Next = edge;
		}
		else
		{
			node->Edge = edge;
		}
	}

	void Print()
	{
		Node* node = NULL;
		Edge* edge = NULL;

		if ((node = Head) == NULL)
			return;

		while (node != NULL)
		{
			cout << node->Data << " : ";

			if ((edge = node->Edge) == NULL)
			{
				node = node->Next;
				cout << endl;

				continue;
			}

			while (edge != NULL)
			{
				cout << edge->Target->Data;
				edge = edge->Next;
			}

			cout << endl;
		}
	}

	void DFS(Node* node)
	{
		cout << node->Data;

		node->Visited = true;

		Edge* edge = node->Edge;

		while (edge != NULL)
		{
			if (edge->Target != NULL && edge->Target->Visited == false)
				DFS(edge->Target);
			
			edge = edge->Next;
		}
	}
};

typedef Graph<char> G;

int main()
{
	G graph;

	//노드 생성
	G::Node* n1 = G::CreateNode('A');
	G::Node* n2 = G::CreateNode('B');
	G::Node* n3 = G::CreateNode('C');
	G::Node* n4 = G::CreateNode('D');
	G::Node* n5 = G::CreateNode('R');

	//노드 추가 및 연결
	graph.AddNode(n1);
	graph.AddNode(n2);
	graph.AddNode(n3);
	graph.AddNode(n4);
	graph.AddNode(n5);

	//간선 그리기
	graph.AddEdge(n1, G::CreateEdge(n1, n2));
	graph.AddEdge(n1, G::CreateEdge(n1, n3));
	graph.AddEdge(n1, G::CreateEdge(n1, n4));
	graph.AddEdge(n1, G::CreateEdge(n1, n5));

	graph.AddEdge(n2, G::CreateEdge(n2, n1));
	graph.AddEdge(n2, G::CreateEdge(n2, n3));
	graph.AddEdge(n2, G::CreateEdge(n2, n5));

	graph.AddEdge(n3, G::CreateEdge(n4, n1));
	graph.AddEdge(n3, G::CreateEdge(n4, n5));

	graph.AddEdge(n4, G::CreateEdge(n5, n1));
	graph.AddEdge(n4, G::CreateEdge(n5, n2));
	graph.AddEdge(n4, G::CreateEdge(n5, n4));

	graph.Print();

	graph.DFS(n1);

	return 0;
}

/*
	4 5

	0 0 1 1 0
	0 1 0 1 1
	1 0 1 0 1
	0 0 1 1 0

	1로 둘러싸인 0범위가 1개라고 쳣을 때,
	위 맵은 6이 출력되도록 만들기.
*/