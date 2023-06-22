#pragma once

#include "Engine/Rendering.h"

class Sonic;

class SonicShooter //��(�հ���) ����
{
public:
	SonicShooter(void (* const way)(Sonic* const)); // ������ ���ο��� way���� ����ϰ� ��.

	bool Update();

	void Move(float const distance); //�켱 ���Ʒ��θ� ��������

	void Shoot(); // 

private:
	Engine::Rendering::Image::Component Skin;

	void(* const Way)(Sonic* const);//�Լ� ������ way �Ҵ�(� �Լ��� ������� Ȯ������ �ʾ��� �� )
	//���� ���ε� ���·� �����ϴ� ���� -> �����Լ� ���̺��̾���

};

