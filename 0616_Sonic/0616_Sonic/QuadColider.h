#pragma once

//�ʷϻ� �׵θ� �浹ü, �浹�ϸ� ����� �ٲ��

#include "Engine/Input.h"
#include "Engine/Physics.h"
#include "Engine/Quadrangle.h"
#include "Engine/Rendering.h"
#include "Engine/Time.h"

struct QuadColider
{
	QuadColider()//�����ڿ��� �ʱ�ȭ���� ������.
	{
		Skin.Length = { 250, 250 }; //ũ��
		Skin.Location = { 300, 0 }; //��ġ
		Skin.Name = "Image/GBB";

		Body.Length = { 250, 250 };
		Body.Center = {300, 0};
	}

	void Update()
	{
		if (Engine::Input::Get::Key::Press(VK_NUMPAD4)) //Ű���� ���� Ű�е� ����Ű
			Skin.Location[0] = Body.Center.x -= Speed * Engine::Time::Get::Delta();
		if (Engine::Input::Get::Key::Press(VK_NUMPAD6)) 
			Skin.Location[0] = Body.Center.x += Speed * Engine::Time::Get::Delta();
		if (Engine::Input::Get::Key::Press(VK_NUMPAD5))
			Skin.Location[1] = Body.Center.y -= Speed * Engine::Time::Get::Delta();
		if (Engine::Input::Get::Key::Press(VK_NUMPAD8))
			Skin.Location[1] = Body.Center.y += Speed * Engine::Time::Get::Delta();

		Skin.Render();
	}

	float const Speed = 500;

	Engine::Rendering::Image::Component Skin{}; //ĳ���� �̹���
	Engine::Physics::Component<Quadrangle> Body{}; //�浹ü ���
};