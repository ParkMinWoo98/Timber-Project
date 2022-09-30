#include "Player.h"
#include "Tree.h"
#include "../Manager/InputMgr.h"

Player::Player(Texture& texPlayer)
	:SpriteObj(texPlayer), texPlayer(texPlayer),
	texRip(*resourceMgr->GetTexture("Rip png")),
	treePtr(nullptr), originalPos(2), pos(Sides::Right), isAlive(true), isChopping(false)
{
	// axe 생성, 위치
	axe.setTexture(*resourceMgr->GetTexture("axe png"));
	Utils::SetOrigin(this->axe, Origins::MR);
	Vector2f size = GetSize();
	axePos.x = -size.x * 0.4f + 5;
	axePos.y = -size.y * 0.4f + 12;
	SetOrigin(Origins::BC);
	
	// sound
	dieSound.setBuffer(*resourceMgr->GetSoundBuffer("die sound wav"));
	chopSound.setBuffer(*resourceMgr->GetSoundBuffer("chop sound wav"));
}

Player::~Player()
{
}

void Player::Set()
{
	centerPos = treePtr->GetPosition();
}

void Player::Init()
{
	isAlive = true;
	isChopping = false;
	sprite.setTexture(texPlayer, true);
	Utils::SetOrigin(sprite, Origins::BC);
	SpriteObj::SetFlipX(pos == Sides::Left);

	Vector2f size = GetSize();
	originalPos[(int)Sides::Left].x = centerPos.x - size.x * 2;
	originalPos[(int)Sides::Left].y = centerPos.y;
	originalPos[(int)Sides::Right].x = centerPos.x + size.x * 2;
	originalPos[(int)Sides::Right].y = centerPos.y;
	SetPosition(originalPos[(int)pos]);
}

void Player::Release()
{
}

void Player::Update(float dt)
{
	SpriteObj::Update(dt);
	if (!isAlive)
		return;
	if (InputMgr::GetKeyDown(Keyboard::Key::Left) && !isChopping)
		Chop(Sides::Left);
	if (InputMgr::GetKeyDown(Keyboard::Key::Right) && !isChopping)
		Chop(Sides::Right);
	if (pos == Sides::Left)
		isChopping = InputMgr::GetKey(Keyboard::Key::Left);
	else if (pos == Sides::Right)
		isChopping = InputMgr::GetKey(Keyboard::Key::Right);
}

void Player::Draw(RenderWindow& window)
{
	SpriteObj::Draw(window);
	if (isChopping)
	{
		window.draw(axe);
	}
}

void Player::SetPosition(Vector2f pos)
{
	SpriteObj::SetPosition(pos);
	Vector2f axePos2 = axePos;
	if (axe.getScale().x < 0)
	{
		axePos2.x *= -1;
	}
	axe.setPosition(pos + axePos2);
}

void Player::SetFlipX(bool flip)
{
	SpriteObj::SetFlipX(flip);

	Vector2f scale = axe.getScale();
	scale.x = flip ? -abs(scale.x) : abs(scale.x);
	axe.setScale(scale);
}

void Player::SetTreePtr(Tree* ptr)
{
	treePtr = ptr;
}

bool Player::GetAlive() const
{
	return isAlive;
}

Sides Player::GetPos() const
{
	return pos;
}

void Player::Kill()
{
	isAlive = false;
	isChopping = false;

	// rip sprite로 변경(안 뒤집히도록)
	sprite.setTexture(texRip, true);
	Utils::SetOrigin(sprite, Origins::BC);
	SpriteObj::SetFlipX(false);
	dieSound.play();
}

void Player::Chop(Sides side)
{
	pos = side;
	SetFlipX(pos == Sides::Left);
	SetPosition(originalPos[(int)pos]);
	chopSound.play();

	treePtr->ShowLogEffect();
}