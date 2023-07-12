#pragma once

#include <vector>

#include "Engine/Game.h"
#include "Engine/Rendering.h"

class Scene;
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
    Scene* scene{ nullptr };

    static std::vector<Sonic*> Sonics;
};

class Object abstract
{
public:
    virtual ~Object() = default;

    virtual void Update() abstract;

    virtual void Render()
    {
        Skin->Render();
    }

protected:
    Engine::Rendering::Image::Component * Skin = nullptr;
};

