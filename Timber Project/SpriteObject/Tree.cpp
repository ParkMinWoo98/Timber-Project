#include "Tree.h"
#include "Player.h"

Tree::Tree(const Vector2f& pos)
	:SpriteObj(*resourceMgr->GetTexture("treebody png"), pos), currentBranch(-1), playerPtr(nullptr)
{
    // branches 생성
    for (int i = 0; i < 6; ++i)
    {
        branches.push_back(new Branch(sprite));
        if (i == 0)
            branches[i]->SetSide(Sides::Left);
        else
        {
            branches[i]->SetSide((Sides)Utils::Range(0, 3));
        }
    }
    // branches 값 초기화
    float x = branches[0]->GetPosition().x;
    float y = 800;
    float offset = branches[0]->GetSize().y;
    offset += 100;
    for (int i = 0; i < branches.size(); ++i)
    {
        branchPos.push_back(Vector2f(x, y));
        y -= offset;
    }
    UpdateBranches();

    // Logs Pool 생성
    for (int i = 0; i < 100; ++i)
    {
        auto log = new EffectLog(*resourceMgr->GetTexture("log png"), 5.f);
        unuseLogs.push_back(log);
    }
}

Tree::~Tree()
{
}

void Tree::Init()
{
    branches[0]->SetSide(Sides::Left);
    for (int i = 1; i < 6; ++i)
    {
        branches[i]->SetSide((Sides)Utils::Range(0, 3));
    }
    UpdateBranches();
}

void Tree::Release()
{
    for (auto log : unuseLogs)
    {
        delete log;
    }
    unuseLogs.clear();

    for (auto log : useLogs)
    {
        delete log;
    }
    useLogs.clear();
}

void Tree::Update(float dt)
{
    // branch 하강
    UpdateBranches();
    // log 시간 지났으면 삭제
    auto it = useLogs.begin();
    while (it != useLogs.end())
    {
        (*it)->Update(dt);
        if (!(*it)->GetActive())
        {
            unuseLogs.push_back(*it);
            it = useLogs.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Tree::Draw(RenderWindow& window)
{
    SpriteObj::Draw(window);
    for (auto branch : branches)
    {
        branch->Draw(window);
    }
    for (auto log : useLogs)
    {
        log->Draw(window);
    }
}

void Tree::SetPlayerPtr(Player* ptr)
{
    playerPtr = ptr;
}

void Tree::UpdateBranches()
{
    currentBranch = (currentBranch + 1) % branches.size();
    for (int i = 0; i < branches.size(); ++i)
    {
        int index = (currentBranch + i) % branches.size();
        branches[index]->SetPosition(branchPos[i]);
        if (i == branches.size() - 1)
        {
            branches[index]->SetSide((Sides)Utils::Range(0, 3));
        }
    }
}

void Tree::ShowLogEffect()
{
    if (unuseLogs.empty())
        return;

    auto log = unuseLogs.front();
    unuseLogs.pop_front();
    useLogs.push_back(log);

    Vector2f force;
    force.x = playerPtr->GetPos() == Sides::Left ? 1500 : -1500;
    force.y = -1500;

    float aForce = playerPtr->GetPos() == Sides::Left ? 360 * 5 : -360 * 5;

    Vector2f pos = GetPosition();
    pos.y = branches[currentBranch]->GetPosition().y;
    log->SetPosition(pos);
    log->Fire(force, aForce);
}

void Tree::ClearLog()
{
    auto it = useLogs.begin();
    while (it != useLogs.end())
    {
        unuseLogs.push_back(*it);
        it = useLogs.erase(it);
    }
}
