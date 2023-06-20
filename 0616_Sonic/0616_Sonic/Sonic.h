#pragma once

#include "Engine/Rendering.h"

class Sonic
{
public:
	Sonic(Vector<2> const location); // 수학적 의미의 벡터(z축은 쓰지 않음) 2D니까. 0번째가 x, 1번쨰가 y

	bool Update();

private:
	Engine::Rendering::Animation::Component Skin; //캐릭터 외관에 관한 컴포넌트를 가져온 것.
};

