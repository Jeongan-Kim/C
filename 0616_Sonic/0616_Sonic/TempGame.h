#pragma once

#include "Engine/Game.h"
#include "Engine/Rendering.h"

//이미 쏴버린 소닉들을 관리

class Sonic;
class SonicShooter;

class TempGame : public Engine::Game
{
public:
	void Start() override;
	void Update() override;
	void End() override;

private:
	static void Add(Sonic* const sonic); //생성된 소닉을 벡터에 저장


private:
	Engine::Rendering::Camera Camera;

	SonicShooter* Shooter;

	static std::vector<Sonic*> Sonics; // 총알(소닉들)들을 벡터로 static 선언을 통해 외부에서도 전역변수처럼 쓸 수 있게.
};

