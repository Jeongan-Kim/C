#pragma once

#include "Engine/Rendering.h"

class Sonic
{
public:
    Sonic(Vector<2> const location);

    bool Update();

private:
    Engine::Rendering::Animation::Component Skin;
};

