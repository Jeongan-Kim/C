#include <algorithm>

#include "Engine/Time.h"

#include "Sonic.h"
#include "SonicShooter.h"

SonicShooter::SonicShooter(void(* const way)(Sonic* const))
    : Way{ way }
{
    Skin.Name = "Image/Direction";
    Skin.Length = { 128, 128 };
    Skin.Location = { -575, 250 };
}

bool SonicShooter::Update()
{
    Skin.Render();

    return true;
}

void SonicShooter::Move(Vector<2> const direction)
{
    Vector<2> const boundary{ (1280 - Skin.Length[0]) * 0.5f, (720 - Skin.Length[1]) * 0.5f }; //화면 밖으로 나갈 수 없도록 바운더리를 정해줌
    //화면 중앙에서부터 화면 크기에서 캐릭터 크기를 제외하고 움직일 수 있는 범위.

    for (int i = 0; i < 2; i++)
        Skin.Location[i] = std::clamp(Skin.Location[i] + direction[i] * MoveSpeed * Engine::Time::Get::Delta(), -boundary[i], boundary[i]); //clamp특정 범위 내에 값을 가두고 싶을 떄 사용함. 값이 101일때 최대값이 100이면 100 반환하듯
}



Sonic* SonicShooter::Shoot()
{
    return new(Sonic){ Skin.Location }; //위치값 받아와서 그 위치에 생성될 수 있도록.
}

