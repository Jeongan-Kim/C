#include <iostream>

using namespace std;

/*
    상속 접근 지정자     부모 클래스          자식클래스
    public              public              public
                        protected           protected
                        private             접근 불가

    protected           public              protected
                        protected           protected
                        private             접근 불가

    private             public              private
                        protected           private
                        private             접근 불가
*/

class Base //부모 클래스
{
private:
    int privateData;

protected:
    int protectedData;

public:
    int publicData;
    void Test() {}
};

class Derived : private Base //상속 접근 지정자 private
{
public: //아무리 여기서 public으로 해도 다음 자식 클래스에서는 사용 불가. 상속 접근 지정자를 우선으로 제한시키기 때문에. 객체를 생성해도 불가.
    Derived()
    {
        Test();
        publicData;
        protectedData;
        //privateData; 이건 불가
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
        //전부 사용 불가.
    }
};

int main()
{
    A a;

	return 0;
}