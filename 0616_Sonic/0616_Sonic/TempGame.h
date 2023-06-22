#pragma once

#include "Engine/Game.h"
#include "Engine/Rendering.h"

//�̹� ������ �Ҵе��� ����

class Sonic;
class SonicShooter;

class TempGame : public Engine::Game
{
public:
	void Start() override;
	void Update() override;
	void End() override;

private:
	static void Add(Sonic* const sonic); //������ �Ҵ��� ���Ϳ� ����


private:
	Engine::Rendering::Camera Camera;

	SonicShooter* Shooter;

	static std::vector<Sonic*> Sonics; // �Ѿ�(�Ҵе�)���� ���ͷ� static ������ ���� �ܺο����� ��������ó�� �� �� �ְ�.
};

