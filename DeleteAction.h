#pragma once
#include "Action.h"
#include "GameObject.h"
#include "Cell.h"
#include "Grid.h"

class DeleteAction : public Action
{
    CellPosition cellpos;

public:
    DeleteAction(ApplicationManager *pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~DeleteAction();
};
