#include "Player.h"
#include "Tree.h"
#include "../Manager/InputMgr.h"

Player::Player(Texture& texPlayer, KeyModes keyMode)
	:SpriteObj(texPlayer), texPlayer(texPlayer),
	texRip(*resourceMgr->GetTexture("graphics/rip.png")), keyMode(keyMode),
	treePtr(nullptr), score(0), timer(0.f), originalPos(2), pos(Sides::Right), isAlive(true), isChopping(false)
{
	// axe 생성, 위치
	axe.setTexture(*resourceMgr->GetTexture("graphics/axe.png"));
	Utils::SetOrigin(this->axe, Origins::MR);
	Vector2f size = GetSize();
	axePos.x = -size.x * 0.4f + 5;
	axePos.y = -size.y * 0.4f + 12;
	SetOrigin(Origins::BC);
	
	// sound
	dieSound.setBuffer(*resourceMgr->GetSoundBuffer("sound/death.wav"));
	chopSound.setBuffer(*resourceMgr->GetSoundBuffer("sound/chop.wav"));
	timeOutSound.setBuffer(*resourceMgr->GetSoundBuffer("sound/out_of_time.wav"));
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
	Set();
	score = 0;
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
	timer -= dt;
	switch (keyMode)
	{
	case KeyModes::FirstPlayer:
		{
			if (InputMgr::GetKeyDown(Keyboard::Key::A) && !isChopping)
				Chop(Sides::Left);
			if (InputMgr::GetKeyDown(Keyboard::Key::D) && !isChopping)
				Chop(Sides::Right);
			if (pos == Sides::Left)
				isChopping = InputMgr::GetKey(Keyboard::Key::A);
			else if (pos == Sides::Right)
				isChopping = InputMgr::GetKey(Keyboard::Key::D);
		}
		break;
	case KeyModes::SecondPlayer:
		{
			if (InputMgr::GetKeyDown(Keyboard::Key::Left) && !isChopping)
				Chop(Sides::Left);
			if (InputMgr::GetKeyDown(Keyboard::Key::Right) && !isChopping)
				Chop(Sides::Right);
			if (pos == Sides::Left)
				isChopping = InputMgr::GetKey(Keyboard::Key::Left);
			else if (pos == Sides::Right)
				isChopping = InputMgr::GetKey(Keyboard::Key::Right);
		}
		break;
	}
	if (CheckDeath())
	{
		
	}
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

void Player::SetTimer(float duration)
{
	timer = duration;
}

void Player::SetTexPlayer(Texture& texplayer)
{
	texPlayer = texplayer;
}

void Player::SetTreePtr(Tree* ptr)
{
	treePtr = ptr;
}

bool Player::GetAlive() const
{
	return isAlive;
}

bool Player::TimeOut() const
{
	return timer == 0;
}

Sides Player::GetPos() const
{
	return pos;
}

bool Player::CheckDeath()
{
	if (isAlive && (timer < 0.f || pos == treePtr->GetCurrentBranchSide()))
	{
		if (timer < 0.f)
			timeOutSound.play();
		else
			dieSound.play();
		timer = 0.f;
		isAlive = false;
		isChopping = false;

		// rip sprite로 변경(안 뒤집히도록)
		sprite.setTexture(texRip, true);
		Utils::SetOrigin(sprite, Origins::BC);
		SpriteObj::SetFlipX(false);
		if(pos == treePtr->GetCurrentBranchSide())
		return true;
	}
	return false;
}

void Player::Chop(Sides side)
{
	pos = side;
	SetFlipX(pos == Sides::Left);
	SetPosition(originalPos[(int)pos]);
	chopSound.play();
	score += 10;
	timer += 0.2f;
	treePtr->UpdateBranches();
	treePtr->ShowLogEffect();
}