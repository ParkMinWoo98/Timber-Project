#pragma once
#include "SpriteObj.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

using namespace sf;

class Button : public SpriteObj
{
protected:
	Sound movingSound;
	Sound selectedSound;

	Vector2f initSize;

	Button(const Button&);
	Button& operator=(const Button&);
public:
	Button(const Texture& tex, const Vector2f& pos = Vector2f());
	virtual ~Button();

	virtual void Init();

	void ButtonEffect();
	void EndEffect();
	void SelectedSoundEffect();
};

