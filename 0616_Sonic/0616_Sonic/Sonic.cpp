#include "Sonic.h"

Sonic::Sonic(Vector<2> const location)
{
	Skin.Name = "Animation/Sonic_Run"; //[4]�� ������ 4��� �Ŷ� �̸����� �ȳ־��.
	Skin.Length = { 144, 144 };
	Skin.Location = location;
	Skin.Duration = 0.125f; // 0.125�ʸ��� �ݺ�
	Skin.Repeatable = true;

}

bool Sonic::Update()
{
	return false;
}
