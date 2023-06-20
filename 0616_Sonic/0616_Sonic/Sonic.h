#pragma once

#include "Engine/Rendering.h"

class Sonic
{
public:
	Sonic(Vector<2> const location); // ������ �ǹ��� ����(z���� ���� ����) 2D�ϱ�. 0��°�� x, 1������ y

	bool Update();

private:
	Engine::Rendering::Animation::Component Skin; //ĳ���� �ܰ��� ���� ������Ʈ�� ������ ��.
};

