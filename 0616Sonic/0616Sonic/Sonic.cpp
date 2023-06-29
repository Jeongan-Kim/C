#include "Engine/Time.h"

#include "Sonic.h"

Sonic::Sonic(Vector<2> const location)
{
    Skin.Name = "Animation/Sonic_Run";
    Skin.Length = { 144, 144 };
    Skin.Location = location;
    Skin.Duration = 0.125f;
    Skin.Repeatable = true;
}

bool Sonic::Update()
{
    Skin.Render();

    //if ((640 + Skin.Length[0] * 0.5) <= (Skin.Location[0] += 0.125f))
    //    return false;
    //else
    //    return true;

    return (Skin.Location[0] += 1280 * Engine::Time::Get::Delta()) <= (640 + Skin.Length[0] * 0.5f);        
}
