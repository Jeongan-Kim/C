/*
	standard template library(STL)

	- �����̳�(container) : ��ü�� �����ϴ� ��ü.(�� ��ü�� �ڷᱸ����� ����)
	- �ݺ���(iterator) : this �����Ͷ� ����� ����. �����̳ʿ� ������ ���ҵ鿡 ������ �� �ְ� ���ִ� ��
	- �˰���(algorithm) : ����, ���� ����� ������ ��
	- �Լ���(functor) : ��ü�� �Լ�ó�� ����� �� �ִ� ��.
*/
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <Queue>

using namespace std;

/*
	Container
	- ���� : sequence, associative, adapter
*/

void SequenceContainer(); 
void AssociativeContainer();
void AdapterContainer();

int main()
{
	SequenceContainer();
	AssociativeContainer();

	////stoi => string to int (���ڿ��� ������ �ٲ� �� ���)
	//string str1 = "123";
	//string str2 = "456";

	//cout << str1 + str2 << endl; // 123456

	//int i1 = stoi(str1);
	//int i2 = stoi(str2);

	//cout << i1 + i2 << endl; //579

	AdapterContainer();
	return 0;
}

/*
	SequenceContainer
	- �����͸� '����(�迭ó��)'���� �����ϴ� �����̳�
*/
void SequenceContainer()
{
	/*
		Vector : �迭ó�� ���µ� ���� ���� ���̴� �����̳�, ũ�⿹���� �����ϰ�, ���԰� ������ ����, �������� ������ ó���� �ϱ� ����
	*/
	{
		cout << "Vector" << endl;

		vector<int> vec; //���� �迭 �Ҵ�

		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		for (const auto& ele : vec)
			cout << ele << ' ';
		cout << endl << endl;
	}

	//Deque
	//- ���Ͷ� ��������� �޸� ������ ���������� ��������� ����.(���ͺ��� ������ �Ҵ��� ��������, ���� ������ �ִ� ���ҵ��� ������ �����Ƿ� �޸𸮰� ���� ��)
	//- ���� ����, ������ ���ͺ��� �� ����. ũ�� ������ �ϱⰡ ����
	{
		cout << "Deque" << endl;

		deque<int> deq;

		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);//�ڷ� �̾� ���̱�
			deq.emplace_front(i); //�տ� �߰��ϱ�
		}

		for (const auto& ele : deq)
			cout << ele << ' ';
		cout << endl << endl;
	}

	//list
	//- ���۰� ������ ����ؼ� ���� ������ ���ؼ��� ���ʷ� �����ؾ� ��
	//- ���� ���ҵ��� �յ��� ������ �˰� ����. ��������� ����Ű�� ����.
	{
		cout << "List" << endl;
		list<int> list;

		for (int i = 0; i < 10; i++)
			list.push_back(i);

		for (const auto& ele : list)
			cout << ele << ' ';
		cout << endl << endl;
	}
}



/*
	associative container
	- �����͸� ������ ��Ģ�� ���� �����ϰ� �����ϴ� �����̳�
	- 2��Ʈ��(?), �ڵ����� ���ĵǾ� ���� ���ϴ� ���� ã�� �ӵ��� ����
	- Ű(key), ��(value)
*/
void AssociativeContainer()
{
	/*
		set(Ű�� �ߺ��� ������� ����) / multiset(Ű�� �ߺ��� �����)
	*/
	{
		cout << "Set" << endl;
		
		set<string> strset1; //�ڷ����� string�� ��

		strset1.insert("Hello");//���� ����, Hello ��ü�� �� ���� key
		strset1.insert("World");//key 2
		strset1.insert("Hello");//�ߺ��� ������� �����Ƿ� �̰��� key�� �ƴ�
		//�ߺ� üũ : �� ���ڸ����� üũ

		cout << strset1.size() << endl; //set�� ������ 2(key)�� �ΰ���

		for (const auto& ele : strset1)
			cout << ele << ' ';
		cout << endl << endl;
	}

	{
		cout << "MultiSet" << endl;

		multiset<string> strset2; //�ڷ����� string�� ��

		strset2.insert("Hello");//���� ����, Hello ��ü�� �� ���� key
		strset2.insert("World");//key 2
		strset2.insert("Hello");//�ߺ��� ����ϹǷ� key 3

		cout << strset2.size() << endl; //set�� ������ 3, key�� ������

		for (const auto& ele : strset2)
			cout << ele << ' ';

		//���ҵ��� ���ԵǸ鼭 �ڵ����� ���ĺ� ������ ���ĵǾ� ����.
		cout << endl << endl;
	}

	/*
		map(Ű�� �ߺ��� ������� ����) / multimap(Ű�� �ߺ��� �����)
	*/
	{
		cout << "Map" << endl;

		map<char, int> map; //<key, value>
		map['c'] = 50; //key�� c, value�� 50 -> mapping
		map['a'] = 10;
		map['d'] = 40;
		map['b'] = 20;

		cout << map['a'] << endl;

		map['a'] = 100;

		cout << map['a'] << endl;

		//key���� �߽����� ������ ���� �־� ����.

		for (const auto& ele : map)
			cout << ele.first << ' ' << ele.second << endl;
		cout << endl;
	}
	{
		cout << "Multimap" << endl;

		multimap<char, int> multimap;
		multimap.insert(pair<char, int>('a', 10)); //pair�������� insertŰ����� ���� ���� ����.(�׳� map��)
		multimap.insert(pair<char, int>('b', 100));
		multimap.insert(make_pair('a', 10000)); //make pair : �ڷ��� ���� �ʾƵ� ��.(2017���� �̻���ʹ� pair�� �Ƚᵵ �ǰ� ���)
		//a�� �ߺ��ؼ� �־� �� ��.
		//pair�� �� �ΰ����� ���� �� �ִ� ����üó�� ���� ��

		cout << multimap.count('a') << endl; //2. a�� �ΰ��� ����ִٴ� ��

		for (const auto& ele : multimap)
			cout << ele.first << ' ' << ele.second << endl;
		cout << endl;

		//multimap.empty(); //����� �ִ��� Ȯ��
		//multimap.clear(); //��� ����
		//{
		//	char answer;
		//	cin >> answer;
		//	multimap.find(answer)->second; //answer�� Ű, second�� ��
		//}

		for (const auto& ele : multimap)
			cout << ele.first << ' ' << ele.second << endl;
		cout << endl;
	}

	/*
		unordered associative container(Ʈ���� ����ؼ� ������ �Ǵ� ���°� �ƴ�) : �ؽ� ���̺��̶�� ���� �����(�˾ƺ���).
		- unordered_set
		- unordered_map
	*/
}

/*
	AdapterContainer
	-������ ������� ���� ����� �� �����ϰų� �������Ͽ� Ư�� ��ɸ� �����ϴ� ��.
	-������ ������� �����̳�.
*/
void AdapterContainer()
{
	/*
		Stack(vector�� ������ ��)
		- LIFO(���Լ���) ���
	*/

	{
		cout << "Stack" << endl;

		stack<int> stack;

		stack.push(1); //���� ����. push adds a copy(�����ؼ� �־� �ִ� ��)
		stack.emplace(2); //emplace constructs a new object(���Ӱ� �����ؼ� �״�� �־��ִ� ��) : ���� ȿ���������� ū ���̴� ����.
		stack.emplace(3);

		//push vs emplace : �̵� ����� ��Ҷ� emplace�� ���ٶ�� �˾Ƶ���.

		cout << stack.top() << endl; //���� �������� �� ���� ���/ 3 ���
		stack.pop(); //���� �������� �� �� ����/ 3 ����
		cout << stack.top() << endl << endl; //2 ���
	}


	/*
		Queue
		-FIFO(first in first out), �������� �����
	*/
	{
		cout << "Queue" << endl;

		queue<int> queue;

		queue.push(1);
		queue.push(2);
		queue.push(3);

		cout << queue.front() << ' ' << queue.back() << endl; //�� �ڷ� �����ؼ� ����� �� ����
		queue.pop(); //����
		cout << queue.front() << ' ' << queue.back() << endl;
	}

	/*
		Priority Queue(�켱 ���� ť. ������ �Ǿ�����. ���� �ͺ��� ������� ������������)
		�� �� ���ҿ� ���� ������ �ƴ϶� ���� ���� ū ���Ұ� ��ġ�ϰ� ��.
	*/
	{
		cout << "Priority Queue" << endl;

		priority_queue<int> priorityQue;

		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			priorityQue.push(n);

		for (int i = 0; i < 10; i++)
		{
			cout << priorityQue.top() << endl;
			priorityQue.pop();//���� ���� �� ���Ұ� �ƴ϶� ���ĵǾ����Ƿ� ���� �� ����(ū ����)�� �����
		}
	}
}
/*
	���� �Է��� �ܾ� ������ ����غ� �� m, n �����
	�ܾ� ���� m�� �°� �ܾ �Է�.
	���� ������ n�� ���� ������ ���� ��.
	�ܾ �Է��ϸ� ���ڰ� ���
	���ڸ� �Է��ϸ� �ܾ ���
	//stoi => string to int (���ڿ��� ������ �ٲ� �� ���)

	//m = 3
	//n = 2
	1. apple
	2. grapes
	3. peach

	1 -> apple
	peach -> 3
*/