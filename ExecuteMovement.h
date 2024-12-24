#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"
class ExecuteMovement :
    public Action
{
public:
    ExecuteMovement(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~ExecuteMovement();
};

