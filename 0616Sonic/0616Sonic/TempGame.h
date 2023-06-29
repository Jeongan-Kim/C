#pragma once

#include <vector>

#include "Engine/Game.h"
#include "Engine/Rendering.h"

class Sonic;
class SonicShooter;

class TempGame : public Engine::Game
{
public:
    void Start()  override;
    void Update() override;
    void    End() override;

private:
    static void Add(Sonic* const sonic);

private:
    Engine::Rendering::Camera Camera;

    Engine::Rendering::Text::Component WorldTime;
    Engine::Rendering::Text::Component SomeTime;

    SonicShooter* Shooter;

    static std::vector<Sonic*> Sonics;
};

