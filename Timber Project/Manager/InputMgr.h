#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

// static�Լ��� �̿��ؼ� Ű���� �� ���콺 �Է��� �˻��� �� �ִ� Ŭ����

using namespace sf;
using namespace std;

class InputMgr
{
private:
	static vector<bool> downList;
	static vector<bool> ingList;
	static vector<bool> upList;
	static list<Keyboard::Key> keyList;
public:
	static void ClearInput();
	static void UpdateInput(const Event& ev);

	static bool GetKeyDown(Keyboard::Key key);
	static bool GetKey(Keyboard::Key key);
	static bool GetKeyUp(Keyboard::Key key);
};
