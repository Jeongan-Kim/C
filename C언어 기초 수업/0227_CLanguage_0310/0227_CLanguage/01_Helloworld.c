#include <stdio.h> //std + io
/*
�⺻������!
std : standard
io : input/output
.h : �������

*/

int main() //main �Լ�, ���α׷����� �ϴ� ��, ���α׷����� ������, ��ȣ ��ü�� �Լ�
/*
{ �Լ��� ����
} �Լ��� ��
*/
{
	printf("Hello, World!\n"); //���, \n : �ٹٲ�, ; : ������ �����ٴ� �ǹ�(�� ���̱�!!)
	/*
	Escape sequence(�������� �˾ƿ���-����)
	-\n, \t(��, ���� ĭ ����, 8ĭ). \a....

	*/
	
	printf("10\n");
	printf("%d\n", 10); //d �ȿ� 10�� ������� �ǹ�, d�� ����, format specifier(conversion specifier,���� ������)
	printf("%d\t %d %d %d %d\n", 1, 2, 3, 4, 5);
	
	printf("�ȳ��ϼ���. �������Դϴ�.\n ���̴� % d���̰�, ��̴� ���Ӱ� �丮�Դϴ�.\n �� mbti�� ENFP�Դϴ�.\n", 29);

	return 0; //��ȯ, �Լ��� ����ɶ� ��ȯ ���� ��ȯ�����ν� ���Ḧ �˸�
}

/*
�̸� : 
���� : 
��� :
MBTI :

*/

/*
���� ����
-Escape sequence
-format specifier

*/
