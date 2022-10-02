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
	// texPlayer를 reference로 사용하면, resourcemgr의 텍스쳐를 나타내게 됨
	// 따라서 texPlayer의 값을 변경해주면 resourcemgr의 texture들이 변경되어 버림
	// 다른 오브젝트들은 texture를 reference형식으로 저장하려고 하지 않고, 불러오자마자 sprite에 set하는 용도로만 쓰고 날려서 문제가 없음
	// resourcemgr의 get에서 const를 붙였지만 반환값이 포인터 형이라 포인터를 따라간 주소의 값은 변경됨
	Texture& texRip;

	KeyModes keyMode;

	int score;
	float timer;

	Sprite axe;
	Vector2f axePos;
	bool isChopping;

	Sound dieSound;
	Sound chopSound;
	Sound timeOutSound;

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

	void SetTimer(float duration);

	void SetTexPlayer(Texture& texplayer);
	void SetTreePtr(Tree* ptr);

	bool GetAlive() const;
	bool TimeOut() const;
	Sides GetPos() const;

	bool CheckDeath();
	void Chop(Sides side);
};

