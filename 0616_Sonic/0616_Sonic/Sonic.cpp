#include "Sonic.h"

Sonic::Sonic(Vector<2> const location)
{
	Skin.Name = "Animation/Sonic_Run"; //[4]는 동작이 4라는 거라서 이름에는 안넣어도됨.
	Skin.Length = { 144, 144 };
	Skin.Location = location;
	Skin.Duration = 0.125f; // 0.125초마다 반복
	Skin.Repeatable = true;

}

bool Sonic::Update()
{
	return false;
}
