#pragma once

#include "Engine/Input.h"
#include "Engine/Physics.h"
#include "Engine/Circle.h"
#include "Engine/Rendering.h"
#include "Engine/Time.h"

struct CircleColider
{
	CircleColider()//생성자에서 초기화부터 해주자.
	{
		Skin.Length = { 250, 250 }; //크기
		Skin.Location = { -300, 0 }; //위치
		Skin.Name = "Image/GBC";

		Body.Radius = 125;
		Body.Center = { -300, 0 };
	}

	void Update()
	{
		if (Engine::Input::Get::Key::Press('A')) //키보두 숫자 키패드 방향키
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

	Engine::Rendering::Image::Component Skin{}; //캐릭터 이미지
	Engine::Physics::Component<Circle> Body{}; //충돌체 모양
};