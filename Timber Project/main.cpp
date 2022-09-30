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
    while (window.isOpen())
    {
        Time dt = clock.restart();
        Event ev;
        while (window.pollEvent(ev))
        {
            InputMgr::UpdateInput(ev);
        }
        InputMgr::ClearInput();
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