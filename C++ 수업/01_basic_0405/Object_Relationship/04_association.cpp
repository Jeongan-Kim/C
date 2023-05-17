#include <iostream>
#include <vector>
//���� ����
using namespace std;

class Patient
{
	string name;
	friend class Doctor; // ���� Ŭ�������� ȯ�� Ŭ������ ��Ҹ� ��� ���
	vector<class Doctor*> doctors; //ȯ�ڵ��� �ǻ� �̸� �迭�� ���� vector �����迭

public:
	Patient(const string& name)
		:name(name)
	{}

	void AddDoctor(class Doctor* const doctor) //���� �ּҵ� ������� �ʰ� const
	{
		doctors.push_back(doctor);
	}

	void MeetDoctor(); //���� Ŭ������ �� �ؿ� �����Ƿ� ���Ǻδ� �Ʒ��� �� ��� ��
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

	void MeetPatient()//ȯ�� Ŭ������ ���� �־ ���⼭ �����ص� ��
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
	Patient* p1 = new Patient("Kim"); //�� �����ͷ�?
	Patient* p2 = new Patient("Lee");
	Patient* p3 = new Patient("Park");

	Doctor* d1 = new Doctor("Doc. Lee");
	Doctor* d2 = new Doctor("Doc. Kim");

	//�ǻ�� ȯ�ڰ� ���� �˾ƾ� �ϴϱ�
	p1->AddDoctor(d1);
	d1->AddPatient(p1);

	p2->AddDoctor(d2);
	d2->AddPatient(p2);

	p3->AddDoctor(d2);
	d2->AddPatient(p3);

	//�̷��� ���μ��� ���̸� �ϳ��� �ٲ�� �Ѵ� ������ ����� ��.(Ŀ�ø� ����)

	//������ ����������(��������) : LIFO �������� ����(last in first out) ���Լ���
	delete d2;
	delete d1;
	delete p3;
	delete p2;
	delete p1;
	return 0;
}

