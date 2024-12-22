#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"

class SwichToDesignMode : public Action
{
public:
    SwichToDesignMode(ApplicationManager *pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~SwichToDesignMode();
};
