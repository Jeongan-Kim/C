#include <iostream>
#include <vector>
//연계 관계
using namespace std;

class Patient
{
	string name;
	friend class Doctor; // 닥터 클래스에서 환자 클래스의 요소를 사용 허용
	vector<class Doctor*> doctors; //환자들의 의사 이름 배열을 위함 vector 동적배열

public:
	Patient(const string& name)
		:name(name)
	{}

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
	Doctor(const string& name)
		:name(name)
	{}

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

