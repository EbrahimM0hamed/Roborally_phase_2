#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
class UseConsumable : public Action
{
    int choice;

public:
    UseConsumable(ApplicationManager *pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~UseConsumable();
};
