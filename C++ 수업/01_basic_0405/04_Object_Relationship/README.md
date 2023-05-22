# 01_object_relationship(객체 관계)

## Composition(구성) part-of
- 전체 클래스를 부품 클래스에서 분담하는 것, 전체 클래스의 객체가 소멸하면 부품 클래스 객체도 소멸함(생명 주기를 공유함)

## Aggregation(집합) has-a
- 특정 클래스 기능 일부를 다른 클래스에서 분담하는 것. (생명 주기를 공유하지는 않음)

## Association(연계) uses-a
- 다른 클래스의 참조 변수 매개로 받음.(서로에게 영향을 끼치는, 커플링 관계), 서로 엮인 클래스

## Dependency(의존) depend-on
- 특정 클래스가 다른 클래스의 기능을 잠깐 사용하는 것. 연계보다 엮인 정도가 낮음.

## Inheritance(상속) is-a
- 어떠한 클래스가 다른 클래스의 기능과 속성을 물려 받는 것.

    |					|			| 관계 형태   | 다른 클래스에 속할수 있는가  |멤버의 존재를 클래스가 관리		|방향성 |
    |-------------------|:-----------:|:------------:|:----------------------------:|:---------------------------------:|:------------:|
   |Composition(구성)    | part-of     |전체/부품                   |No			              |Yes			    |단방향 |
   |Aggregation(집합)     |has-a       |전체/부품                   |Yes				          |No				|단방향 |
   |Association(연계)     |uses-a      |용도 외엔 무관              |Yes				          |No				|단방향 or 양방향|
   |Dependency(의존)      |depends-on  |옹도 외엔 무관              |Yes				          |Yes			    |단방향|

- 결합도 : 서로 다른 클래스 간의 의존하는 정도. 낮을 수록 좋음
- 응집도 : 한 클래스 내부의 요소들이 서로 관련되어 있는 정도. => 객체 지향의 캡슐화, 높을 수록 좋음


# 02_Cpmopsition(구성 관계)
```cpp
class Point2D
{
public:
	int x;
	int y;
};

class Monster
{
	string name;
	Point2D position1; // 다른 클래스지만 이 클래스가 소멸되면 같이 사라짐.
	Point2D* position2;

public:
	//composition
	Monster(int x, int y)
	{
		position1.x = x; //클래스 전체와 다른 클래스 부분이 엮임.
		position1.y = y;
	}
	//Aggregation
	Monster(Point2D* point)
	{
		this->position2 = point;
	}
};

int main()
{
	Monster mon1(10, 20);  // 다른 클래스지만 이 클래스가 소멸되면 position1도 같이 사라짐.

	Point2D point;
	Monster mon2(&point); //이렇게 하면 point 객체는 사라지지 않게 됨.

	return 0;
}
```

# 03_Aggregation(집합 관계)
선생님과 학생이 강좌 정보를 공유하는 것을 예시로 알아보자.
## teacher.h
```cpp
class Teacher
{
	std::string name;
public:
	Teacher(const std::string name)	:name(name)	{}
	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name; }
};
```

## student.h
```cpp
class Student
{
	std::string name;
	int count;
public:
	Student(const std::string& name, int count = 0)
		: name(name), count(count)	{}

	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name; }

	auto GetCount() const { return count; }
	void SetCount(const std::string& count) { this->count; }
};
```

## lecture.h
```cpp
class Lecture
{
	std::string name;
	Teacher* teacher;
	std::vector<Student*> students; //학생은 여러명이니 벡터로 동적할당

public:
	Lecture(const std::string& name):name(name)	{}

	void AssignmentTeacher(Teacher* teacher) //선생님 할당
	{
		this->teacher = teacher;
	}

	void AssignmentStudent(Student* student) //학생 할당
	{
		students.push_back(student);
	}

	void Print() //주소를 찍는 것
	{
		std::cout << "teacher : " << teacher << std::endl;

		for (const auto& student : students) //학생은 벡터니까 범위기반 for문으로 찍어주자.
			std::cout << "student : " << student << std::endl;

		std::cout << std::endl;
	}
};
```

## main.cpp
```cpp
using namespace std;

	Teacher t("teacher");
	Student s1("a");
	Student s2("b");
	Student s3("c");

	cout << "t: " << &t << endl;
	cout << "s1 : " << &s1 << endl;
	cout << "s2 : " << &s2 << endl;
	cout << "s3 : " << &s3 << endl;

	{
		Lecture lec("C++");
		lec.AssignmentTeacher(&t);
		lec.AssignmentStudent(&s1);
		lec.AssignmentStudent(&s2);
		lec.AssignmentStudent(&s3);
		lec.Print();

		/*
			t: 000000B24BBBF268
			s1 : 000000B24BBBF2A8
			s2 : 000000B24BBBF2F8
			s3 : 000000B24BBBF348
			teacher : 000000B24BBBF268
			student : 000000B24BBBF2A8
			student : 000000B24BBBF2F8
			student : 000000B24BBBF348
		*/
	}
	//괄호 나오면 lec이 사라짐

	cout << "t: " << &t << endl;
	cout << "s1 : " << &s1 << endl;
	cout << "s2 : " << &s2 << endl;
	cout << "s3 : " << &s3 << endl;
	//본체가 사라져도 부품은 사라지지 않음

	/*
	t: 000000B24BBBF268
	s1 : 000000B24BBBF2A8
	s2 : 000000B24BBBF2F8
	s3 : 000000B24BBBF348
	*/
```

# 04_Association(연계 관계)
의사와 환자의 엮인 관계를 통해 알아보자.
```cpp
class Patient
{
	string name;
	friend class Doctor; // 닥터 클래스에서 환자 클래스의 요소를 사용 허용
	vector<class Doctor*> doctors; //환자들의 의사 이름 배열을 위함 vector 동적배열

public:
	Patient(const string& name)	:name(name) {}

	void AddDoctor(class Doctor* const doctor) //값도 주소도 변경되지 않게 const
	{
		doctors.push_back(doctor);
	}

	void MeetDoctor(); //닥터 클래스가 이 밑에 있으므로 정의부는 아래에 써 줘야 함
};

class Doctor
{
	string name;
	friend class Patient;
	vector<class Patient*> patients;

public:
	Doctor(const string& name)	:name(name)	{}

	void AddPatient(class Patient* const patient)
	{
		patients.push_back(patient);
	}

	void MeetPatient()//환자 클래스가 위에 있어서 여기서 정의해도 됨
	{
		for (const auto& patient : patients)
			cout << "Meet patient : " << patient->name << endl;
	}
};

void Patient::MeetDoctor()
{
	for (const auto& doctor : doctors)
		cout << "Meet doctor : " << doctor->name << endl;
}

int main()
{
	Patient* p1 = new Patient("Kim"); //왜 포인터로?
	Patient* p2 = new Patient("Lee");
	Patient* p3 = new Patient("Park");

	Doctor* d1 = new Doctor("Doc. Lee");
	Doctor* d2 = new Doctor("Doc. Kim");

	//의사와 환자가 서로 알아야 하니까
	p1->AddDoctor(d1);
	d1->AddPatient(p1);

	p2->AddDoctor(d2);
	d2->AddPatient(p2);

	p3->AddDoctor(d2);
	d2->AddPatient(p3);

	//이렇게 서로서로 묶이면 하나가 바뀌면 둘다 문제가 생기게 됨.(커플링 관계)

	//해제는 마지막부터(역순으로) : LIFO 형식으로 해제(last in first out) 후입선출
	delete d2;
	delete d1;
	delete p3;
	delete p2;
	delete p1;
	return 0;
}
```

## 객체를 포인터로 동적 할당을 통해 메모리를 할당하고 관리하는 이유
- 객체의 수명을 함수 호출을 벗어나도 유지하고자 할 때
- 여러 객체 간의 참조 관계를 유지하고 관리할 때
- 객체를 동적으로 생성하여 메모리 사용을 최적화하고자 할 때

# 05_Dependencies(의존 관계)
노동자 클래스가 타이머 클래스를 잠시 사용만 하는 것으로 알아보자
```cpp
class Timer
{
	time_point<high_resolution_clock> start_time;
public:
	Timer()
	{
		start_time = high_resolution_clock::now(); //현재 시간으로 초기화
	}

	void Elapsed()
	{
		auto current_time = high_resolution_clock::now();
		duration<double, std::milli>delta = current_time - start_time; //경과된 시간 계산

		cout << delta.count() << endl;
	}
};

class Worker
{
public:
	void DoSomething()
	{
		Timer timer; //얼마나 일했는가
		for (int i = 0; i < 100000000; i++); //그냥 시간만 보내게끔 쓴 것.
		timer.Elapsed(); //잠깐 가져다 쓰는 것.
	}
};

int main()
{
	Worker w;
	w.DoSomething();

	return 0;
}
```