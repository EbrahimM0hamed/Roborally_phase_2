#pragma once
#include "Action.h"
#include "GameObject.h"
#include "Cell.h"
#include "Grid.h"

class CopyAction : public Action
{
protected:
    // return the game object if there is and NULL is there isn't
    GameObject *gameObject;
    CellPosition cellpos;

public:
    CopyAction(ApplicationManager *pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
};