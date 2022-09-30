#include <SFML/Graphics.hpp>
#include "Manager/SceneMgr.h"

int main()
{
    SceneMgr sceneMgr;
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!!", Style::Default);

    Clock clock;
    while (window.isOpen())
    {
        Time dt = clock.restart();

        sceneMgr.Draw();
        window.display();
    }
    return 0;
}