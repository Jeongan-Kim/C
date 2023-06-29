#pragma once

//초록색 테두리 충돌체, 충돌하면 레드로 바뀌게

#include "Engine/Input.h"
#include "Engine/Physics.h"
#include "Engine/Quadrangle.h"
#include "Engine/Rendering.h"
#include "Engine/Time.h"

struct QuadColider
{
	QuadColider()//생성자에서 초기화부터 해주자.
	{
		Skin.Length = { 250, 250 }; //크기
		Skin.Location = { 300, 0 }; //위치
		Skin.Name = "Image/GBB";

		Body.Length = { 250, 250 };
		Body.Center = {300, 0};
	}

	void Update()
	{
		if (Engine::Input::Get::Key::Press(VK_NUMPAD4)) //키보두 숫자 키패드 방향키
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

	Engine::Rendering::Image::Component Skin{}; //캐릭터 이미지
	Engine::Physics::Component<Quadrangle> Body{}; //충돌체 모양
};