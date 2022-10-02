#include <SFML/Graphics.hpp>
#include "Manager/SceneMgr.h"
#include "Manager/InputMgr.h"

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!!", Style::Default);

    Clock clock;
    Time dt;

    SceneMgr sceneMgr(window, dt);
    sceneMgr.Init();
    while (window.isOpen())
    {
        dt = clock.restart();

        InputMgr::ClearInput();
        Event ev;
        if (window.pollEvent(ev))
        {
            InputMgr::UpdateInput(ev);
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
            continue;
        }
        sceneMgr.Update();

        window.clear();

        sceneMgr.Draw(window);
        window.display();
    }
    sceneMgr.Release();
    return 0;
}