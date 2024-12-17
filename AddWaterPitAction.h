#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "WaterPit.h"

class AddWaterPitAction : public Action
{
    CellPosition WaterPitPosition;
    
public:
    AddWaterPitAction(ApplicationManager *pApp);
    virtual void ReadActionParameters(); // Reads action parameters
    virtual void Execute();
    ~AddWaterPitAction();
};
