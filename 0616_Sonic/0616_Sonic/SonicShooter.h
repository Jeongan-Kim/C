#pragma once

#include "Engine/Rendering.h"

class Sonic;

class SonicShooter //총(손가락) 구현
{
public:
	SonicShooter(void (* const way)(Sonic* const)); // 생성자 내부에서 way값을 사용하게 됨.

	bool Update();

	void Move(float const distance); //우선 위아래로만 움직이자

	void Shoot(); // 

private:
	Engine::Rendering::Image::Component Skin;

	void(* const Way)(Sonic* const);//함수 포인터 way 할당(어떤 함수를 사용할지 확정되지 않았을 때 )
	//동적 바인딩 형태로 저장하는 형태 -> 가상함수 테이블이었음

};

