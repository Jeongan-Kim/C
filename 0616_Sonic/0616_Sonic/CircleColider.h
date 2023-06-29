#pragma once

#include "Engine/Input.h"
#include "Engine/Physics.h"
#include "Engine/Circle.h"
#include "Engine/Rendering.h"
#include "Engine/Time.h"

struct CircleColider
{
	CircleColider()//�����ڿ��� �ʱ�ȭ���� ������.
	{
		Skin.Length = { 250, 250 }; //ũ��
		Skin.Location = { -300, 0 }; //��ġ
		Skin.Name = "Image/GBC";

		Body.Radius = 125;
		Body.Center = { -300, 0 };
	}

	void Update()
	{
		if (Engine::Input::Get::Key::Press('A')) //Ű���� ���� Ű�е� ����Ű
			Skin.Location[0] = Body.Center.x -= Speed * Engine::Time::Get::Delta();
		if (Engine::Input::Get::Key::Press('D'))
			Skin.Location[0] = Body.Center.x += Speed * Engine::Time::Get::Delta();
		if (Engine::Input::Get::Key::Press('S'))
			Skin.Location[1] = Body.Center.y -= Speed * Engine::Time::Get::Delta();
		if (Engine::Input::Get::Key::Press('W'))
			Skin.Location[1] = Body.Center.y += Speed * Engine::Time::Get::Delta();

		Skin.Render();
	}

	float const Speed = 500;

	Engine::Rendering::Image::Component Skin{}; //ĳ���� �̹���
	Engine::Physics::Component<Circle> Body{}; //�浹ü ���
};