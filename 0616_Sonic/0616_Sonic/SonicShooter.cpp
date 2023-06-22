#include "SonicShooter.h"

#include "Sonic.h"
#include "SonicShooter.h"


SonicShooter::SonicShooter(void(* const way)(Sonic* const))
	:Way{ way }
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

void SonicShooter::Move(float const distance)
{
	Skin.Location[1] += distance;
}

void SonicShooter::Shoot()
{
	Way(new Sonic(Skin.Location)); //Location을 객체로 넘겨주면서, 소닉 객체가 생성하여 소닉객체의 주소를 Way에 넣어 호출하는것.
}  
