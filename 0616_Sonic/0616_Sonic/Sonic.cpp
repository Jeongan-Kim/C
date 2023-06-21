#include "Sonic.h"
#include "Engine/Time.h"

Sonic::Sonic(Vector<2> const location)
{
	Skin.Name = "Animation/Sonic_Run"; //[4]는 동작이 4라는 거라서 이름에는 안넣어도됨.
	Skin.Length = { 144, 144 };
	Skin.Location = location;
	Skin.Duration = 0.125f; // 재생 시간 간격. 0.125초마다 반복
	Skin.Repeatable = true;

}

bool Sonic::Update() //업데이트 부분에서 캐릭터 외관을 렌더링
{
	Skin.Render(); //외관 렌더링

	//소닉이 화면 밖을 나갔을 때는 없어지도록.(몸의 절반 이상이 나가면 false를 반환하여 없어질 수 있도록)
	//if ((640 + Skin.Length[0] * 0.5) <= (Skin.Location[0] += 0.125f)) 
	//   return false;
	//else
	//   return true;

	//이렇게 해도 됨.
	return (Skin.Location[0] += 1280 * Engine::Time::Get::Delta()) <= (640 + Skin.Length[0] * 0.5f);
	//Delta타임은 프레임 간 경과 시간. 1280 : 화면의 너비를 나타내는 상수
	//게임엔진 타임이라고 보면 된다.(1280은 화면 크기, Del화면 업데이트 시간을 말한다.)
	//한 걸음 움직일때 걸리는 시간을 일정하게 엔진 흐름 시간으로 통일 시켜주는 것...


}