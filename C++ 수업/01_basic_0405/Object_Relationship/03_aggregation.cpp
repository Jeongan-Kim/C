#include "03_lecture.h"
//집합 관계
// 선생님, 학생이 강의를 공유하는 것을 예시로 알아보자

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
	return 0;
}

