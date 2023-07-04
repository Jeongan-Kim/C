#include <iostream>

// �ѹ������� ���ٰ� ���� ������ �ٽ� �������� ���ƿͼ� �Ȱ� �� �ٽ� �ı�
// ���ʿ��� ��츦 �������� �� �ϹǷ� ��Ʈ��ŷ���ٴ� ��츦 ���� �� ����

/*
	���(������ ��Ÿ��, �����Ͱ� �������), ����(��带 ������)���� �׷��� �׷����� ���� ��
	�� ������ ���� �� �� �ִ� ������ ���� Ž��.
	�ش� ������ �湮�ߴ��� ���ߴ��� üũ�ϸ鼭 Ž��.
*/

using namespace std;

template<typename T>
class Graph
{
public:
	struct Node;

	struct Edge //����
	{
		Node* start = NULL; //���� ������
		Node* Target = NULL; //���� ������
		Edge* Next = NULL; // ���� ������ ���� ����
	};

	struct Node
	{
		T data;
		int Index = -1;

		Node* Next = NULL; //����
		Edge* Edge = NULL;

		bool Visited = false; //�湮 ����
	};

private:
	Node* Head = NULL; //��� ���� ù��° ��
	int Count = 0;

public:
	static Edge* CreateEdge(Node* start, Node* target) //���� ���� ��带 �Ű������� �޾� ���� ����
	{
		Edge* edge = new Edge();
		edge->start = start;
		edge->Target = target;

		return edge;
	}

	static Node* CreateNode(T data) //�����͸� �޾� ��� ����
	{
		Node* node = new Node();
		node->Data = data;

		return node;
	}

public:
	void AddNode(Node* node) //�׷����� ��� �߰�
	{
		Node* nodeList = Head; //��� ����ü ��ü ����

		if (nodeList != NULL)
		{
			while (nodeList->Next != NULL)//���� ������ ���� ������ �߰�
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

	//��� ����
	G::Node* n1 = G::CreateNode('A');
	G::Node* n2 = G::CreateNode('B');
	G::Node* n3 = G::CreateNode('C');
	G::Node* n4 = G::CreateNode('D');
	G::Node* n5 = G::CreateNode('R');

	//��� �߰� �� ����
	graph.AddNode(n1);
	graph.AddNode(n2);
	graph.AddNode(n3);
	graph.AddNode(n4);
	graph.AddNode(n5);

	//���� �׸���
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

	1�� �ѷ����� 0������ 1����� ���� ��,
	�� ���� 6�� ��µǵ��� �����.
*/