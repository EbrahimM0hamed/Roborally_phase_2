#pragma once
#include "Action.h"
#include "GameObject.h"
#include "Cell.h"
#include "Grid.h"

class PasteAction : public Action
{
    GameObject *gameObject;
    CellPosition cellpos;

public:
    PasteAction(ApplicationManager *pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~PasteAction();
};
