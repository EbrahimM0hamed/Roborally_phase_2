#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Workshop.h"
class AddWorkshopAction : public Action
{
    CellPosition dangerPosition;
public:
    AddWorkshopAction(ApplicationManager *pApp);
    virtual void ReadActionParameters(); // Reads action parameters
    virtual void Execute(); 
    ~AddWorkshopAction();
};
