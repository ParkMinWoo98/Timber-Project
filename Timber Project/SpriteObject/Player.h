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
	Texture& texPlayer;
	Texture& texRip;

	KeyModes keyMode;

	Sprite axe;
	Vector2f axePos;
	bool isChopping;

	Sound dieSound;
	Sound chopSound;

	Tree* treePtr;
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

	void SetTexPlayer(Texture& texplayer);
	void SetTreePtr(Tree* ptr);

	bool GetAlive() const;
	Sides GetPos() const;

	void CheckDeath();
	void Chop(Sides side);
};

