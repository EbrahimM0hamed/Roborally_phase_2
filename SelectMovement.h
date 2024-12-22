#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"
class SelectMovement : public Action
{
public:
    SelectMovement(ApplicationManager *pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~SelectMovement();
};
