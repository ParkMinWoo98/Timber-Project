#pragma once
#include "SpriteObj.h"
#include "Branch.h"
#include "EffectLog.h"
#include <vector>
#include <list>

using namespace std;

class Player;

class Tree : public SpriteObj
{
protected:
	vector<Branch*> branches;
	int currentBranch;
	vector<Vector2f> branchPos;

	list<EffectLog*> unuseLogs;
	list<EffectLog*> useLogs;

	Player* playerPtr;

	Tree(const Tree&);
	Tree& operator=(const Tree&);
public:
	Tree(const Vector2f& pos = Vector2f());
	virtual ~Tree();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	void SetPlayerPtr(Player* ptr);
	void UpdateBranches();
	void ShowLogEffect();
	void ClearLog();
};

