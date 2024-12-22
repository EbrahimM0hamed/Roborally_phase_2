#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

class SwichToPlayMode : public Action
{
public:
    SwichToPlayMode(ApplicationManager *pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~SwichToPlayMode();
};
