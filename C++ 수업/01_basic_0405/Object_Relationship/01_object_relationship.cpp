

/*
	Object Relationship : 객체 관계

	- Composition(구성) part-of : 전체 클래스를 부품 클래스에서 분담하는 것, 전체 클래스의 객체가 소멸하면 부품 클래스 객체도 소멸함(생명 주기를 공유함)

	- Aggregation(집합) has-a : 특정 클래스 기능 일부를 다른 클래스에서 분담하는 것. (생명 주기를 공유하지는 않음)

	- Association(연계) uses-a : 다른 클래스의 참조 변수 매개로 받음.(서로에게 영향을 끼치는, 커플링 관계), 서로 엮인 클래스

	- Dependency(의존) depend-on : 특정 클래스가 다른 클래스의 기능을 잠깐 사용하는 것. 연계보다 엮인 정도가 낮음.

	- Inheritance(상속) is-a : 어떠한 클래스가 다른 클래스의 기능과 속성을 물려 받는 것.



									 관계 형태    다른 클래스에 속할수 있는가  멤버의 존재를 클래스가 관리		방향성
   Composition(구성)     part-of     전체/부품                   No			              Yes			    단방향
   Aggregation(집합)     has-a       전체/부품                   Yes				          No				단방향
   Association(연계)     uses-a      용도 외엔 무관              Yes				          No				단방향 or 양방향
   Dependency(의존)      depends-on  옹도 외엔 무관              Yes				          Yes			    단방향

   결합도 : 서로 다른 클래스 간의 의존하는 정도. 낮을 수록 좋음
   응집도 : 한 클래스 내부의 요소들이 서로 관련되어 있는 정도. => 객체 지향의 캡슐화, 높을 수록 좋음
*/

