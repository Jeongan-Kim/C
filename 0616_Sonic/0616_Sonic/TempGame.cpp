#include <string>

#include "Engine/Input.h"
#include "Engine/Time.h"

#include "Sonic.h"
#include "SonicShooter.h"

#include "TempGame.h"

#include "QuadColider.h"
#include "CircleColider.h"

QuadColider QC;
CircleColider CC;

std::vector<Sonic*> TempGame::Sonics;

void TempGame::Start()
{
    Camera.Sight = { 1280, 720 };

    WorldTime.Font.Name = "Consolas";
    WorldTime.Font.Size = 48;
    WorldTime.Color.Red = 255;
    WorldTime.Length = { 1000, 50 };
    WorldTime.Location = { 500, 25 };

    SomeTime = WorldTime;

    SomeTime.Location[1] += 50;

    Shooter = new SonicShooter(Add);
}

void TempGame::Update()
{
    std::string time = "World Time : " + std::to_string(Engine::Time::Get::Elapsed());
    std::string time2 = "Delta Time : " + std::to_string(Engine::Time::Get::Delta()); //프레임 간 걸리는 시간.

    WorldTime.Text = time.data();
    SomeTime.Text = time2.data();

    WorldTime.Render();
    SomeTime.Render();

    Camera.Sight[0] += 16 * 4 * -Engine::Input::Get::Wheel::V();
    Camera.Sight[1] += 9 * 4 * -Engine::Input::Get::Wheel::V();
    Camera.Set();

    //for (Sonic* const sonic : Sonics)
    //    sonic->Update();

    //줌인을 했을때 화면 끝까지 가지 않고 위치에 맞게 삭제되도록 해보자.
    std::vector<Sonic*>::iterator i = Sonics.begin(); //iterator사용해서 특정 원소를 가리키게

    while (i != Sonics.end())
    {
        if ((**i).Update() == true) //i는 포인터이므로 더블포인터 써야함
        {
            i = i + 1;
        }
        else
        {
            delete(*i);

            i = Sonics.erase(i);
        }
    }

    QC.Update();
    CC.Update();

    if (QC.Body.Collide(CC.Body) == true)
    {
        QC.Skin.Name = "Image/RBB";
        CC.Skin.Name = "Image/RBC";
    }
    else
    {
        QC.Skin.Name = "Image/GBB";
        CC.Skin.Name = "Image/GBC";
    }

    Shooter->Update();

    Vector<2> direction{};

    if (Engine::Input::Get::Key::Press(VK_LEFT)) direction[0] -= 1;
    if (Engine::Input::Get::Key::Press(VK_RIGHT)) direction[0] += 1;

    if (Engine::Input::Get::Key::Press(VK_UP)) direction[1] += 1;
    if (Engine::Input::Get::Key::Press(VK_DOWN)) direction[1] -= 1;

    if (direction[0] != 0 and direction[1] != 0)
        direction = Normalize(direction);

    Shooter->Move(direction);

    if (Engine::Input::Get::Key::Down(VK_SPACE))
        Sonics.push_back(Shooter->Shoot());
}

void TempGame::End()
{
    delete(Shooter);

    for (Sonic* const sonic : Sonics)
        delete(sonic);
}

void TempGame::Add(Sonic* const sonic)
{
    Sonics.push_back(sonic);
}
