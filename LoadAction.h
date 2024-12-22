#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
class LoadAction : public Action
{
    string file;

public:
    LoadAction(ApplicationManager *pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    ~LoadAction();
};
