#include <iostream>

using namespace std;

/*
    ��� ���� ������     �θ� Ŭ����          �ڽ�Ŭ����
    public              public              public
                        protected           protected
                        private             ���� �Ұ�

    protected           public              protected
                        protected           protected
                        private             ���� �Ұ�

    private             public              private
                        protected           private
                        private             ���� �Ұ�
*/

class Base //�θ� Ŭ����
{
private:
    int privateData;

protected:
    int protectedData;

public:
    int publicData;
    void Test() {}
};

class Derived : private Base //��� ���� ������ private
{
public: //�ƹ��� ���⼭ public���� �ص� ���� �ڽ� Ŭ���������� ��� �Ұ�. ��� ���� �����ڸ� �켱���� ���ѽ�Ű�� ������. ��ü�� �����ص� �Ұ�.
    Derived()
    {
        Test();
        publicData;
        protectedData;
        //privateData; �̰� �Ұ�
    }
};

class A : public Derived
{
public:
    A()
    {
        //Test();
        //publicData;
        //protectedData;
        //���� ��� �Ұ�.
    }
};

int main()
{
    A a;

	return 0;
}