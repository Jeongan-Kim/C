#pragma once

#include "Engine/Rendering.h"

class Sonic;

class SonicShooter
{
public:
    SonicShooter(void (* const way)(Sonic* const));

    bool Update();

    void Move(Vector<2> const direction); // 벡ㅌㅓ로 방향을 받아서 사방으로 총도 움직일 수 있게끔

    //void Shoot();
    Sonic* Shoot(); //소닉 슈터의 소닉 객체를 만드는 것.

private:
    Engine::Rendering::Image::Component Skin;

    float const MoveSpeed = 750;

    void(* const Way)(Sonic* const);
};

