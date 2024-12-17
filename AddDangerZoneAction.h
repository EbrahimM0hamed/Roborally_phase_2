#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "DangerZone.h"
class AddDangerZoneAction : public Action
{
    CellPosition dangerPosition;
public:
    AddDangerZoneAction(ApplicationManager *pApp);
    virtual void ReadActionParameters(); // Reads action parameters

    virtual void Execute(); // Creates a new flag Object
                            // then Sets this flag object to the GameObject Pointer of its Cell

    ~AddDangerZoneAction();
};
