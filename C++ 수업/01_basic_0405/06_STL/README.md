# 01_STL_and_container

- 컨테이너(container) : 객체를 저장하는 객체.(이 자체로 자료구조라고도 말함)
- 반복자(iterator) : this 포인터랑 비슷한 개념. 컨테이너에 보관된 원소들에 접근할 수 있게 해주는 것
- 알고리즘(algorithm) : 랜덤, 정렬 등등을 포함한 것
- 함수자(functor) : 객체를 함수처럼 사용할 수 있는 것.

## Container
- 종류 : sequence, associative, adapter

### SequenceContainer
- 데이터를 '선형(배열처럼)'으로 저정하는 컨테이너

#### Vector
배열처럼 쓰는데 가장 많이 쓰이는 컨테이너, 크기예측이 가능하고, 삽입과 삭제가 불편, 연속적인 데이터 처리를 하기 좋음
```cpp
vector<int> vec; //동적 배열 할당

for (int i = 0; i < 10; i++)
	vec.push_back(i);

for (const auto& ele : vec)
	cout << ele << ' ';

/*
0 1 2 3 4 5 6 7 8 9
*/
```

#### Deque
- 벡터랑 비슷하지만 메모리 공간에 연속적으로 저장되지는 않음.(벡터보다 데이터 할당이 빠르지만, 서로 떨어져 있는 원소들을 가지고 있으므로 메모리가 좀더 듬)
- 원소 삽입, 삭제가 벡터보다 더 편리함. 크기 예측을 하기가 힘듬
```cpp
deque<int> deq;

for (int i = 0; i < 10; i++)
{
	deq.push_back(i);//뒤로 이어 붙이기
	deq.emplace_front(i); //앞에 추가하기
}

for (const auto& ele : deq)
	cout << ele << ' ';

/*
9 8 7 6 5 4 3 2 1 0 0 1 2 3 4 5 6 7 8 9
*/
```

#### list
- 시작과 끝만을 기억해서 원소 접근을 위해서는 차례로 접근해야 함
- 각각 원소들은 앞뒤의 정보만 알고 있음. 양방향으로 가리키는 형태.
```cpp
list<int> list;

for (int i = 0; i < 10; i++)
	list.push_back(i);

for (const auto& ele : list)
	cout << ele << ' ';

/*
0 1 2 3 4 5 6 7 8 9
*/
```

### associative container
- 데이터를 일정한 규칙에 따라서 저장하고 관리하는 컨테이너
- 2진트리(?), 자동으로 정렬되어 들어가서 원하는 값을 찾는 속도가 빠름
- 키(key), 값(value)

#### Set
- 키의 중복을 허용하지 않음
```cpp
set<string> strset1; //자료형이 string인 것

strset1.insert("Hello");//원소 삽입, Hello 자체가 한 개의 key
strset1.insert("World");//key 2
strset1.insert("Hello");//중복을 허용하지 않으므로 이것은 key가 아님
//중복 체크 : 맨 앞자리부터 체크
cout << strset1.size() << endl; //set의 사이즈 2(key)가 두개다
for (const auto& ele : strset1)
	cout << ele << ' ';

/*
2
Hello World
*/
```
#### MultiSet
- 키의 중복을 허용함
```cpp
multiset<string> strset2; //자료형이 string인 것

strset2.insert("Hello");//원소 삽입, Hello 자체가 한 개의 key
strset2.insert("World");//key 2
strset2.insert("Hello");//중복을 허용하므로 key 3
cout << strset2.size() << endl; //set의 사이즈 3, key가 세개다
for (const auto& ele : strset2)
	cout << ele << ' ';
//원소들이 삽입되면서 자동으로 알파벳 순으로 정렬되어 들어간다.
/*
3
Hello Hello World
*/
```


#### map
- 키의 중복을 허용하지 않음
```cpp
map<char, int> map; //<key, value>
map['c'] = 50; //key가 c, value가 50 -> mapping
map['a'] = 10;
map['d'] = 40;
map['b'] = 20;
cout << map['a'] << endl;
map['a'] = 100;
cout << map['a'] << endl;
//key값을 중심으로 정렬을 시켜 넣어 놓음.
for (const auto& ele : map)
	cout << ele.first << ' ' << ele.second << endl;

/*
10
100
a 100
b 20
c 50
d 40
*/
```


#### Multimap
- 키의 중복을 허용함
```cpp
multimap<char, int> multimap;
multimap.insert(pair<char, int>('a', 10)); //pair형식으로 insert키워드로 넣을 수도 있음.(그냥 map도)
multimap.insert(pair<char, int>('b', 100));
multimap.insert(make_pair('a', 10000)); //make pair : 자료형 쓰지 않아도 됨.(2017버전 이상부터는 pair도 안써도 되게 허용)
//a를 중복해서 넣어 준 것.
//pair은 딱 두가지만 넣을 수 있는 구조체처럼 보면 됨

cout << multimap.count('a') << endl; //2. a에 두개가 들어있다는 뜻

for (const auto& ele : multimap)
	cout << ele.first << ' ' << ele.second << endl;
cout << endl;

multimap.empty(); //비워져 있는지 확인
multimap.clear(); //모두 비우기
{
	char answer;
	cin >> answer;
	multimap.find(answer)->second; //answer은 키, second은 값
}

for (const auto& ele : multimap)
	cout << ele.first << ' ' << ele.second << endl;

/*
2
a 10
a 10000
b 100
*/
```

### AdapterContainer
- 예전에 만들어진 제한 기능을 또 제한하거나 재정의하여 특정 기능만 수행하는 것.
- 구조로 만들어진 컨테이너.

### Stack
- vector를 변형한 것
- LIFO(후입선출) 방식

```cpp
stack<int> stack;

stack.push(1); //원소 삽입. push adds a copy(복사해서 넣어 주는 것)
stack.emplace(2); //emplace constructs a new object(새롭게 생성해서 그대로 넣어주는 것) : 좀더 효율적이지만 큰 차이는 없음.
stack.emplace(3);

//push vs emplace : 이동 비용이 비쌀때 emplace를 쓴다라고만 알아두자.

cout << stack.top() << endl; //가장 마지막에 들어간 값을 출력/ 3 출력
stack.pop(); //가장 마지막에 들어간 값 삭제/ 3 삭제
cout << stack.top() << endl << endl; //2 출력

/*
3
2
*/
```

#### Queue
- FIFO(first in first out), 선형으로 저장됨
```cpp
queue<int> queue;

queue.push(1);
queue.push(2);
queue.push(3);

cout << queue.front() << ' ' << queue.back() << endl; //앞 뒤로 접근해서 찍어줄 수 있음
queue.pop(); //삭제
cout << queue.front() << ' ' << queue.back() << endl;

/*
1 3
2 3
*/
```

#### Priority Queue
- 우선 순위 큐. 정렬이 되어있음. 높은 것부터 순서대로 내림차순으로
- 맨 앞 원소에 가장 먼저가 아니라 가장 값이 큰 원소가 위치하게 됨.
```cpp
priority_queue<int> priorityQue;

for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
    priorityQue.push(n);

for (int i = 0; i < 10; i++)
{
	cout << priorityQue.top() << endl;
	priorityQue.pop();//가장 먼저 들어간 원소가 아니라 정렬되었으므로 가장 윗 원소(큰 원소)가 사라짐
}

/*
9
8
7
6
5
4
3
2
1
0
*/
```