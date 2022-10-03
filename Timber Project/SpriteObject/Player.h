#pragma once
#include "SpriteObj.h"
#include <SFML/GpuPreference.hpp>
#include <SFML/Audio.hpp>

enum class Sides;
class Tree;

enum class KeyModes
{
	FirstPlayer,
	SecondPlayer
};

class Player : public SpriteObj
{
protected:
	Vector2f centerPos;
	vector<Vector2f> originalPos;
	Sides pos;
	bool isAlive;
	Texture texPlayer;
	// texPlayer�� reference�� ����ϸ�, resourcemgr�� �ؽ��ĸ� ��Ÿ���� ��
	// ���� texPlayer�� ���� �������ָ� resourcemgr�� texture���� ����Ǿ� ����
	// �ٸ� ������Ʈ���� texture�� reference�������� �����Ϸ��� ���� �ʰ�, �ҷ����ڸ��� sprite�� set�ϴ� �뵵�θ� ���� ������ ������ ����
	// resourcemgr�� get���� const�� �ٿ����� ��ȯ���� ������ ���̶� �����͸� ���� �ּ��� ���� �����
	Texture& texRip;

	KeyModes keyMode;

	int score;
	float timer;
	float duration;

	Sprite axe;
	Vector2f axePos;
	bool isChopping;

	Sound dieSound;
	Sound chopSound;
	Sound timeOutSound;

	Tree* treePtr;

	Player(const Player&);
	Player& operator=(const Player&);
public:
	Player(Texture& texPlayer, KeyModes keyMode = KeyModes::FirstPlayer);
	virtual ~Player();

	void Set();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
	virtual void SetPosition(Vector2f pos);
	virtual void SetFlipX(bool flip);

	void SetDuration(float duration);
	void SetTimer(float timer);
	float GetDuration() const;
	float GetTimer() const;

	void SetTexPlayer(Texture& texplayer);
	void SetTreePtr(Tree* ptr);

	bool GetAlive() const;
	bool TimeOut() const;
	Sides GetPos() const;

	bool CheckDeath();
	void Chop(Sides side);
	int GetScore() const;
};

