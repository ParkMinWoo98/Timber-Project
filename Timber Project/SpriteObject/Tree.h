#pragma once
#include "SpriteObj.h"
#include "Branch.h"
#include "EffectLog.h"
#include <vector>
#include <list>

using namespace std;

enum class KeyModes;
class Player;

class Tree : public SpriteObj
{
protected:
	vector<Branch*> branches;
	int currentBranch;
	vector<Vector2f> branchPos;

	list<EffectLog*> unuseLogs;
	list<EffectLog*> useLogs;

	KeyModes keyMode;
	Player* playerPtr;

	Tree(const Tree&);
	Tree& operator=(const Tree&);
public:
	Tree(const Texture& texTree, KeyModes keyMode, const Vector2f& pos = Vector2f());
	virtual ~Tree();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;

	void SetPlayerPtr(Player* ptr);
	void UpdateBranches();
	Sides GetCurrentBranchSide();
	void ShowLogEffect();
	void ClearLog();
};

