#include "UseConsumable.h"


UseConsumable::UseConsumable(ApplicationManager* pApp) : Action(pApp)
{
    int choice=-1;
}

void UseConsumable::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();
    pOut->PrintMessage("Click on the consumable you want to use : 1- ToolKit   2- HackDevice");
    choice=pIn->GetInteger(pOut);
    pOut->ClearStatusBar();
}

void UseConsumable::Execute()
{
    ReadActionParameters();
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Player* pPlayer = pGrid->GetCurrentPlayer();
    if(choice==1)
    {
        if(pPlayer->GetToolkit()>0)
        {
            pPlayer->SetToolkit(-1);
            pPlayer->SetHealth(10);
            pOut->PrintMessage("Toolkit used successfully");
        }
        else
        {
            pOut->PrintMessage("You don't have a toolkit");
        }
    }
    else if(choice==2)
    {
        if(pPlayer->GetNumHacked()>0)
        {
            pGrid->GetNextPlayer()->SetIsHack(true);
            pPlayer->SetNumHacked(-1);
            pOut->PrintMessage("HackDevice used successfully");
        }
        else
        {
            pOut->PrintMessage("You don't have a HackDevice");
        }
    }
    else
    {
        pOut->PrintMessage("Invalid choice");
    }
}

UseConsumable::~UseConsumable()
{
}