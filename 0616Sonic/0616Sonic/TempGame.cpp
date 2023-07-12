#include <string>

#include "Engine/Input.h"
#include "Engine/Time.h"

#include "Sonic.h"
#include "SonicShooter.h"
#include "Scene.h"

#include "TempGame.h"

#include "QuadColider.h"
#include "CircleColider.h"

std::vector<Sonic*> TempGame::Sonics;

QuadColider QC;
CircleCollider CC;

void TempGame::Start()
{
    scene = new Scene;
    Camera.Sight = { 1024, 1024 };

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
    scene->Update();
    scene->Render();

    std::string time = "World Time : " + std::to_string(Engine::Time::Get::Elapsed());
    std::string time2 = "Delta Time : " + std::to_string(Engine::Time::Get::Delta());

    WorldTime.Text = time.data();
    SomeTime.Text = time2.data();

    WorldTime.Render();
    SomeTime.Render();
        
    Camera.Sight[0] += 16 * 4 * -Engine::Input::Get::Wheel::V();
    Camera.Sight[1] += 9 * 4 * -Engine::Input::Get::Wheel::V();
    Camera.Set();

    std::vector<Sonic*>::iterator i = Sonics.begin();

    while (i != Sonics.end())
    {
        if ((**i).Update() == true)
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

    if (Engine::Input::Get::Key::Press(VK_LEFT))  direction[0] -= 0.1;
    if (Engine::Input::Get::Key::Press(VK_RIGHT)) direction[0] += 0.1;
    if (Engine::Input::Get::Key::Press(VK_UP))    direction[1] += 0.1;
    if (Engine::Input::Get::Key::Press(VK_DOWN))  direction[1] -= 0.1;

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
