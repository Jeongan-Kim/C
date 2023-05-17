#include "03_lecture.h"
//���� ����
// ������, �л��� ���Ǹ� �����ϴ� ���� ���÷� �˾ƺ���

int main()
{
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
	//��ȣ ������ lec�� �����

	cout << "t: " << &t << endl;
	cout << "s1 : " << &s1 << endl;
	cout << "s2 : " << &s2 << endl;
	cout << "s3 : " << &s3 << endl;
	//��ü�� ������� ��ǰ�� ������� ����

	/*
	t: 000000B24BBBF268
	s1 : 000000B24BBBF2A8
	s2 : 000000B24BBBF2F8
	s3 : 000000B24BBBF348
	*/
	return 0;
}

