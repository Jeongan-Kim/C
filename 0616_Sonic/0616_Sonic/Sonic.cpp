#include "Sonic.h"
#include "Engine/Time.h"

Sonic::Sonic(Vector<2> const location)
{
	Skin.Name = "Animation/Sonic_Run"; //[4]�� ������ 4��� �Ŷ� �̸����� �ȳ־��.
	Skin.Length = { 144, 144 };
	Skin.Location = location;
	Skin.Duration = 0.125f; // ��� �ð� ����. 0.125�ʸ��� �ݺ�
	Skin.Repeatable = true;

}

bool Sonic::Update() //������Ʈ �κп��� ĳ���� �ܰ��� ������
{
	Skin.Render(); //�ܰ� ������

	//�Ҵ��� ȭ�� ���� ������ ���� ����������.(���� ���� �̻��� ������ false�� ��ȯ�Ͽ� ������ �� �ֵ���)
	//if ((640 + Skin.Length[0] * 0.5) <= (Skin.Location[0] += 0.125f)) 
	//   return false;
	//else
	//   return true;

	//�̷��� �ص� ��.
	return (Skin.Location[0] += 1280 * Engine::Time::Get::Delta()) <= (640 + Skin.Length[0] * 0.5f);
	//DeltaŸ���� ������ �� ��� �ð�. 1280 : ȭ���� �ʺ� ��Ÿ���� ���
	//���ӿ��� Ÿ���̶�� ���� �ȴ�.(1280�� ȭ�� ũ��, Delȭ�� ������Ʈ �ð��� ���Ѵ�.)
	//�� ���� �����϶� �ɸ��� �ð��� �����ϰ� ���� �帧 �ð����� ���� �����ִ� ��...


}