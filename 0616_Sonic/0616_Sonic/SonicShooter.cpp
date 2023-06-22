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
	Way(new Sonic(Skin.Location)); //Location�� ��ü�� �Ѱ��ָ鼭, �Ҵ� ��ü�� �����Ͽ� �Ҵа�ü�� �ּҸ� Way�� �־� ȣ���ϴ°�.
}  
