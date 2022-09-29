#include "InputMgr.h"
#include <iostream>
#include <algorithm>

vector<bool> InputMgr::downList(Keyboard::Key::KeyCount);
vector<bool> InputMgr::ingList(Keyboard::Key::KeyCount);
vector<bool> InputMgr::upList(Keyboard::Key::KeyCount);
list<Keyboard::Key> InputMgr::keyList;

void InputMgr::ClearInput()
{
    for (auto key : keyList)
    {
        downList[key] = false;
    }
    for (auto key : keyList)
    {
        upList[key] = false;
    }
    keyList.clear();
}

void InputMgr::UpdateInput(const Event& ev)
{
    switch (ev.type)
    {
    case Event::EventType::KeyPressed:
        if (ev.key.code != Keyboard::Key::Unknown && !GetKey(ev.key.code))
        {
            keyList.push_back(ev.key.code);
            downList[ev.key.code] = true;
            ingList[ev.key.code] = true;
        }
        break;
    case Event::EventType::KeyReleased:
        if (ev.key.code != Keyboard::Key::Unknown)
        {
            keyList.push_back(ev.key.code);
            ingList[ev.key.code] = false;
            upList[ev.key.code] = true;
        }
        break;
    }
}

bool InputMgr::GetKeyDown(Keyboard::Key key)
{
    return downList[key];
}

bool InputMgr::GetKey(Keyboard::Key key)
{
    return ingList[key];
}

bool InputMgr::GetKeyUp(Keyboard::Key key)
{
    return upList[key];
}
