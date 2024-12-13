#pragma once
#include "Action.h"
#include "GameObject.h"
#include "Cell.h"
#include "Grid.h"

class CopyAction : public Action
{

    GameObject *gameObject;
    CellPosition cellpos;

public:
    CopyAction(ApplicationManager *pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~CopyAction();
};