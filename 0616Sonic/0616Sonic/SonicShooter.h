#pragma once

#include "Engine/Rendering.h"

class Sonic;

class SonicShooter
{
public:
    SonicShooter(void (* const way)(Sonic* const));

    bool Update();

    void Move(Vector<2> const direction);

    //void Shoot();
    Sonic* Shoot();

private:
    Engine::Rendering::Image::Component Skin;

    float const MoveSpeed = 750;

    void(* const Way)(Sonic* const);
};

