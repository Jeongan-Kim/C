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
    Vector<2> const boundary{ (1280 - Skin.Length[0]) * 0.5f, (720 - Skin.Length[1]) * 0.5f };

    for (int i = 0; i < 2; i++)
        Skin.Location[i] = std::clamp(Skin.Location[i] + direction[i] * MoveSpeed * Engine::Time::Get::Delta(), -boundary[i], boundary[i]);
}

Sonic* SonicShooter::Shoot()
{
    return new(Sonic){ Skin.Location };
}


