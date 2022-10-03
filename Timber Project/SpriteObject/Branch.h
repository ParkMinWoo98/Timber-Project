#pragma once
#include "SFML/Graphics.hpp"
#include "SpriteObj.h"

enum class Sides
{
    Left,
    Right,
    None,
};

class Branch : public SpriteObj
{
protected:
    Sprite& treeBody;
    Sides side;
public:
    Branch(const Texture& tex, Sprite& treeBody);
    virtual ~Branch();

    virtual void Init() override;
    virtual void Draw(RenderWindow& window) override;
    void SetSide(Sides side);
    Sides GetSide();
};